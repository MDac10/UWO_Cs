##Megan Da Costa - Student ID: 251009855
##Weekly assignment 5

#Download Libraries necessary
library(Rsubread)
library(ggplot2)

##Change working directory and show what is currently in it
setwd("C:\\Users\\megda\\OneDrive\\Documents\\Projects\\MBI4850")
list.files("data")

##Creates the ref-data folder and transfer the chromosome1 data into it
dir.create("ref-data")
file.copy("chr1.fa.gz", "ref-data")
list.files("ref-data")

##Build the index for chromosome1 file downloaded
buildindex(basename = "chr1_hg19", reference = ".\\ref-data\\chr1.fa.gz", gappedIndex = TRUE, indexSplit = TRUE, memory = 2000)


##Move all files into the ref-data file
file.copy("chr1_hg19.00.b.array", "ref-data")
file.copy("chr1_hg19.00.b.tab", "ref-data")
file.copy("chr1_hg19.files", "ref-data")
file.copy("chr1_hg19.log", "ref-data")
file.copy("chr1_hg19.reads", "ref-data")
list.files("ref-data")

##Quality scores to Phreds for A_1
qs_A1 <- qualityScores(filename = "data/A_1.fastq.gz")
dim(qs_A1)
head(qs_A1, 2)
df_A1 <- c()
for(i in 1:nrow(qs_A1)){
  for(j in 1:ncol(qs_A1)){
    df_A1 <- rbind(df_A1, c(QualityScore = qs_A1[i,j], ReadNumber = i, Position = j))
  }
}

#Converts the data into a data frame and puts the Phred scores into a boxplot
df_A1 <- as.data.frame(df_A1)
df_A1$Position <- as.factor(df_A1$Position)
head(df_A1, 4)
dim(df_A1)
A1_plot <- ggplot(df_A1, aes(x = Position, y = QualityScore.1)) + geom_boxplot(outlier.size = 0.1, outlier.colour = "grey") + theme_light()
jpeg(filename = "A1_plot.jpg") #This will be the plot saved as a jpeg
A1_plot
dev.off()


##Quality scores to Phreds for A_2
qs_A2 <- qualityScores(filename = "data/A_2.fastq.gz")
dim(qs_A2)
head(qs_A2, 2)
df_A2 <- c()
for(i in 1:nrow(qs_A2)){
  for(j in 1:ncol(qs_A2)){
    df_A2 <- rbind(df_A2, c(QualityScore = qs_A2[i,j], ReadNumber = i, Position = j))
  }
}

#Converts the data into a data frame and puts the Phred scores into a boxplot
df_A2 <- as.data.frame(df_A2)
df_A2$Position <- as.factor(df_A2$Position)
head(df_A2, 4)
dim(df_A2)
A2_plot <- ggplot(df_A2, aes(x = Position, y = QualityScore.1)) + geom_boxplot(outlier.size = 0.1, outlier.colour = "grey") + theme_light()
pdf("A2_plot.pdf") #This will be the plot saved as a pdf
A2_plot
dev.off()

#Checking quality scores
##Quality scores to Phreds for B_1 and converted to a data frame 
qs_B1 <- qualityScores(filename = "data/B_1.fastq.gz")
dim(qs_B1)
head(qs_B1, 2)
df_B1 <- c()
for(i in 1:nrow(qs_B1)){
  for(j in 1:ncol(qs_B1)){
    df_B1 <- rbind(df_B1, c(QualityScore = qs_B1[i,j], ReadNumber = i, Position = j))
  }
}

#Converts the data into a data frame and puts the Phred scores into a boxplot
df_B1 <- as.data.frame(df_B1)
df_B1$Position <- as.factor(df_B1$Position)
head(df_B1, 4)
dim(df_B1)
B1_plot <- ggplot(df_B1, aes(x = Position, y = QualityScore.1)) + geom_boxplot(outlier.size = 0.1, outlier.colour = "grey") + theme_light()
B1_plot

#Checking quality scores
##Quality scores to Phreds for B_2 and converted to a data frame 
qs_B2 <- qualityScores(filename = "data/B_2.fastq.gz")
dim(qs_B2)
head(qs_B2, 2)
df_B2 <- c()
for(i in 1:nrow(qs_B2)){
  for(j in 1:ncol(qs_B2)){
    df_B2 <- rbind(df_B2, c(QualityScore = qs_B2[i,j], ReadNumber = i, Position = j))
  }
}

#Converts the data into a data frame and puts the Phred scores into a boxplot
df_B2 <- as.data.frame(df_B2)
df_B2$Position <- as.factor(df_B2$Position)
head(df_B2, 4)
dim(df_B2)
B2_plot <- ggplot(df_B2, aes(x = Position, y = QualityScore.1)) + geom_boxplot(outlier.size = 0.1, outlier.colour = "grey") + theme_light()
B2_plot

##Align reads of all samples to the human reference genome
sample.names <- c("data/A_1.fastq.gz", "data/A_2.fastq.gz", "data/B_1.fastq.gz", "data/B_2.fastq.gz")
for(sample in sample.names) {
  align(index = "ref-data/chr1_hg19", readfile1 = sample) 
}
bam.files <- list.files(path = "data", pattern = ".BAM$", full.names = TRUE)
print(bam.files)

##featureCounts - summarizing information across genes
##Counts
fc <- featureCounts(bam.files, annot.inbuilt = "hg19")
class(fc)
length(fc)
names(fc)
dim(fc$counts)

counts.matrix <- fc$counts
samples <- colnames(counts.matrix)
renamed <- function(sampleName) {
  val <- gsub(x = sampleName, pattern = ".fastq.gz.subread.BAM", replacement = "")
  return(val)
}

sampleIDs <- renamed(samples)
print(samples)
print(sampleIDs)

colnames(counts.matrix) <- sampleIDs
head(counts.matrix, 3)

##Annotations
class(fc$annotation)
dim(fc$annotation)
head(fc$annotation, 3)

##Target
class(fc$targets)
fc$targets

##Stats
head(fc$stat)
dim(fc$stat)
class(fc$stat)

stat.df <- fc$stat
statIDs <- colnames(stat.df)
newIDs <- renamed(statIDs)
print(statIDs)
print(newIDs)

colnames(stat.df) <- sampleIDs
head(stat.df)
