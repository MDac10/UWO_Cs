##Assignment 6
##name - student ID: xxxxxxxxx

if(!requireNamespace("BiocManager", quietly = TRUE))
  install.packages("BiocManager")
BiocManager::install("limma")

if(!requireNamespace("BiocManager", quietly = TRUE))
  install.packages("BiocManager")
BiocManager::install("edgeR")

if(!requireNamespace("BiocManager", quietly = TRUE))
  install.packages("BiocManager")
BiocManager::install("org.Mm.eg.db")

if(!requireNamespace("BiocManager", quietly = TRUE))
  install.packages("BiocManager")
BiocManager::install("Glimma")

install.packages("RColorBrewer")
install.packages("gplots")

install.packages("stringr")
library("stringr")

library("limma")
library("edgeR")
library("org.Mm.eg.db")
library("Glimma")
library("RColorBrewer")
library("gplots")
library("tidyverse")
library("dplyr")

setwd("C:\\Users\\megda\\OneDrive\\Documents\\Projects\\MBI4850")

#Part 1 - Pre-processing the data
#read the sample info
samples <- read.delim("assignment-7/SampleInfo.txt")
View(samples)

sampleinfo <- samples
View(sampleinfo)
substr("Sample.10", start = 8, stop = 10)
sampleinfo$Samples <- substr((sampleinfo$Samples), 8, 10)
sampleinfo$Samples <- as.character(sampleinfo$Samples)

#read the read counts
seqdata <- read.delim("assignment-7/rawCounts.txt", stringsAsFactors = FALSE)
#Q1 - display them
dim(seqdata)
head(seqdata, 3)
print(sampleinfo)

#Remove first column which does not depict the data
countdata <- seqdata[,-(1)]
rownames(countdata) <- seqdata[,1]
head(countdata, 3)
colnames(countdata)
substr("Sample.10", start = 8, stop = 10)
colnames(countdata) <- substr(colnames(countdata), 8, 10)


#countdata is of type list
typeof(countdata)

#convert the data in countdata to a dataframe to be able to make a barplot
q2.df <- data.frame()
for(sample in colnames(countdata)){
  mat <- cbind(Sample = rep(sample, nrow(countdata)), Counts = countdata[,sample])
  q2.df <- rbind(q2.df, mat)
}
q2.df$Counts <- as.numeric(q2.df$Counts)

View(q2.df)

dgeObj.p1 <-DGEList(countdata)
names(dgeObj.p1)
dgeObj.p1$samples
dim(dgeObj.p1$counts)
head(dgeObj.p1$counts, 3)
head(dgeObj.p1$samples, 3)
class(dgeObj.p1$samples)
q2.df <- cbind(Samples = rownames(dgeObj.p1$samples), dgeObj.p1$samples)
head(q2.df, 3)

q2.df$Samples <- as.factor(q2.df$Samples)
q2.df$lib.size <- as.numeric(q2.df$lib.size)

q2.barplot <- ggplot(q2.df, aes(x = Samples, y = lib.size)) + geom_bar(stat = "identity", width = 0.5) + xlab("Samples") + ylab("Library Size") + theme_light()

q2.barplot

#Q4 - Identify and remove samples with reads less than 2000000
belowThresh <- q2.df %>% filter(lib.size < 2000000)
belowThresh

#New sampleinfo file
sampleinfo <- sampleinfo[-c(4, 8, 16),]
View(sampleinfo)

countdata <- select(countdata, -c("4", "8", "16"))
View(countdata)

write.table(sampleinfo, file=".\\assignment-7\\sampleinfo.txt")
write.table(countdata, file=".\\assignment-7\\countdata.txt")


##Part 2 - Filtering Genes and Converting Counts
#Q6 - First normalise to get counts per million
myCPM <- cpm(countdata)
#checking to see that the dimensions for the countdata and the counts per million are the same
dim(countdata)
dim(myCPM)
head(myCPM, 3)

#Create a data frame with the countdata and CPM
gene.df <- data.frame()
for(name in colnames(countdata)){
  matrix <- cbind(CPM = myCPM[, name], Counts = countdata[,name], Sample = rep(name, nrow(countdata)))
  gene.df <- rbind(gene.df, matrix)
}

gene.df$CPM <- as.numeric(gene.df$CPM)
gene.df$Counts <- as.numeric(gene.df$Counts)

View(gene.df)

#Histogram of CPMs and Frequency
q6.hist <- ggplot(data = gene.df, aes(x = CPM)) + geom_histogram(color = "darkgreen", fill = "darkgreen", binwidth = 2) + ggtitle("Distribution of CPM") + labs(y = "Frequency", x = "CPM") + theme_minimal() + xlim(0, 600) + ylim(0, 100)
q6.hist

#Q7 - scatter plots
##Using the DGEList object
q7.scatter <- ggplot(data = gene.df, aes(x = CPM, y = Counts)) + geom_point() + labs(x = "CPM", y = "counts") + theme_minimal()
q7.scatter

#Q8 - greater than the CPM
q8.df <- data.frame()

countdata2 <- countdata
countdata2[, 'Thresh'] <- 0
View(gene.df)
for(i in 1:nrow(gene.df)){
  name <- rownames(gene.df[i,])
  if(gene.df[i, 'CPM'] >= 2.9){
    for(gene.name in rownames(countdata2)){
      if(str_detect(name, gene.name)){
        countdata2[gene.name, 'Thresh'] <- countdata2[gene.name, 'Thresh'] + 1
      }
    }
  }
}

q8.df <- data.frame()
for(i in 1:nrow(countdata2)){
  newrow <- cbind(GeneID = rownames(countdata2[i,]), OverThresh = countdata2[i, 'Thresh'])
  q8.df <- rbind(q8.df, newrow)
}
head(q8.df)
rownames(q8.df)

q8.hist <- ggplot(data = q8.df, aes(x = GeneID)) + geom_histogram(color = "darkgreen", fill = "darkgreen", binwidth = 2) + ggtitle("Gene Reads Over the CPM Threshold") + labs(y = "Number of Samples", x = "Gene") + theme_minimal()
q8.hist

#Q9 - check number of samples
ques9 <- countdata2 %>% filter(Thresh < 14)
ques9

#Q10 - Converting to a DGE object
dgeObj <- DGEList(countdata)
names(dgeObj)

dim(dgeObj$counts)
head(dgeObj$counts, 3)
head(dgeObj$samples, 3)
class(dgeObj$samples)

#Q11
log.cpm <- cpm(dgeObj, log = TRUE)
head(log.cpm, 2)
q11.df <- data.frame()
for(my.sample in colnames(countdata)){
  mat11 <- cbind(Sample = rep(my.sample, nrow(log.cpm)), Log.CPM = log.cpm[,my.sample])
  q11.df <- rbind(q11.df, mat11)
}
q11.df$Log.CPM <- as.numeric(q11.df$Log.CPM)
q11.df$Sample <- as.factor(q11.df$Sample)
q11.boxplot <- ggplot(q11.df, aes(x = Sample, y = Log.CPM)) + geom_boxplot() + xlab("Samples") + ylab("Log CPM") + ggtitle("Distributions of Log CPM Across Samples") + theme_minimal()
q11.boxplot

#Q12
plotMDS(dgeObj)
col.cell <- c("blue", "purple")[sampleinfo$Samples.Condition]
data.frame(sampleinfo$Samples.Condition, col.cell)
plotMDS(dgeObj, col = col.cell)
legend("topleft", fill = c("blue", "purple"), legend = levels(sampleinfo$Samples.Condition))

#Q13
dgeObj13 <- DGEList(countdata)
names(dgeObj13)
dgeObj13$samples

dgeObj13 <- calcNormFactors(dgeObj13)
dgeObj13$samples
