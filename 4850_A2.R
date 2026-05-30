##Assignment 2

#Build a factor of length 10 with 3 levels
game.difficulty <- c("Beginner", "Intermediate", "Master", "Beginner", "Beginner", "Intermediate", "Intermediate", "Beginner", "Master", "Intermediate")
game.factor <- factor(game.difficulty)
levels(game.factor) <- c("B", "Int", "M")

#Making a list
new.list <- list("char1", 35L, c(1:10), matrix(data=12:17, nrow = 3), list(c("element", "2"), c("element", "2")))
names(new.list) <- c("Heading", "Page", "Iteration", "Info-Matrix", "Subsections")

v <- c(1:10)
w <- c(1:5, 11:15)
(v >= w) |(w > (1.5*v))

v <- c(7, 1, -2, -12, -7)

for(i in v){
  if(i <= -10){
    print("This number is less than or equal to -10")
  } else if ((i > -10) & (i < 0)){
    i <- i + 15
    print(i)
  } else{
    print("This number is positive. We do not need to do anything.")
  }
}

#Define a function
Multiple <- function(x){
  return(2*x)
}

#Comparing matrices and data frames
ex.mat <- matrix(data=1:10,nrow = 2)
ex2.mat <- matrix(data=1:3, "error", nrow = 2)

names <- c("Victor", "Janice", "Karen", "Tony", "Moe")
ages <- c(20, 22, 30, 25, 40)
usesRStudio <- c(TRUE, FALSE, FALSE, TRUE, TRUE)
ex.df <- data.frame(names, ages, usesRStudio)

#Exporting DF
min <- c(4L, 3L, 3L, 3L)
collab <- c(FALSE, TRUE, TRUE, FALSE)
artist <- c("HardSometimes", "MyUniverse", "BoyWithLuv", "Anti-Romantic")
music.df <- data.frame(min, collab, artist)
names(music.df) <- c("MinutesInSong", "Collaboration", "SongTitle")

path <- "C:\\Users\\megda\\OneDrive\\Documents\\Projects\\MBI4850\\firstDF.csv"
write.csv(music.df, file = path, row.names = FALSE)

path2 <- "C:\\Users\\megda\\OneDrive\\Documents\\Projects\\MBI4850\\secondDF.xls"
write.table(music.df, file = path2, row.names=FALSE, col.names=TRUE, sep='\t', append=F, quote=FALSE)

#Importing DF
music.data <- read.csv(file = path, stringsAsFactors = FALSE)

#Editing DF
new.row <- data.frame(2L, TRUE, "Sunflower")
colnames(new.row) <- colnames(music.df)
rbind(music.df, new.row)

#While and For loop
val = 1
while(val <= 11){
  print(val)
  val <- val+2
}

my.seq <- seq(from = 2, to = 11, by = 3)
for(x in my.seq){
  print(x)
}

#New function
new.func <- function(N){
  if(N <= 0){
    print("The number is negative.")
  } else if (N > 5){
    N <- N*3
    return(N)
  } else {
    random.vec <- rep(N, N)
    for(i in random.vec){
      print(i)
    }
  }
}

col1 <- c(1, 6, 11)
col2 <- c(2, 7, 12)
col3 <- c(3, 8, 13)
col4 <- c(4, 9, 14)
col5 <- c(5, 10, 15)

list1 <- list(c(100:120), matrix(data = 1:15, nrow = 3, ncol = 5), data.frame(col1, col2, col3, col4, col5))
list1[[2]] <- rbind(list1[[2]], c(0, 0, 0, 0, 0))
list1[[2]] <- cbind(list1[[2]], c(0, 0, 0, 0))
list1[[3]] <- cbind(list1[[3]], col6 = c(0, 0, 0))
list1[[3]] <- rbind(list1[[3]][1:2,], c(0, 0, 0, 0), list1[[3]][3,])
