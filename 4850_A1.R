#Assignment1
#Megan Da Costa - student ID: 251009855

#integer vector example
int.vec <- c(10L, 12L, 13L, 14L)
#double vector example
doub.vec <- c(10.2, 11.11, 45.12, 32.76)
#character vector example
char.vec <- c("These", "are", "my", "strings")
#logical vector examle
logic.vec <- c(TRUE, FALSE, T, F)

#assigning names to a vectors values
names(int.vec) <- c("dogs", "cats", "birds", "butterflies")

##Vectors part
#make new integer vector and select the 4th, 7th, 9th elements based on name
exint.vec <- c(1, 3, 6, 12, 45, 64, 10, 65, 99, 28)
names(exint.vec) <- c("a", "b", "c", "d", "e", "f", "g", "h", "i", "j")
exint.vec[c("d", "g", "i")]

#make new variable without "d", "g", "i"
new.vec <- exint.vec[! names(exint.vec) %in% c("d", "g", "i")]

#make new vector for dimensional changes
exchar.vec <- c("apple", "orange", "kiwi", "carrot", "tomato", "broccoli", "python", "java", "R", "BTS", "1D", "ATEEZ")
dim(exchar.vec) <- c(3,4)

##Martices part
#making a matrix of 4x3
exmtrx <- matrix(1:12, nrow=4)
rownames(exmtrx) <- c("arow", "brow", "crow", "drow")
colnames(exmtrx) <- c("acol", "bcol", "ccol")

#make a char matrix using cbind
songs <- c("Better", "Younger", "Star", "Tide")
artist <- c("Khalid", "Ruel", "Bazzi", "WOODZ")
times <- c("3:49", "3:42", "2:50", "3:56")
musicmtrx <- cbind(songs, artist, times)
rownames(musicmtrx) <- c("Track 1", "Track 2", "Track 3", "Track 4")
colnames(musicmtrx) <- c("Title", "Artist", "Time")

#one line matrix
oneline.mtrx <- matrix(c(21, 22, 32, 19, 165, 179, 154, 185, 106, 125, 134, 147), nrow = 4, dimnames=list(c("Pearl", "Bert", "Sally", "Niki"), c("age", "height", "weight")))

#operations on matrices
num.mtrx <- matrix(c(100, 200, 300, 400, 500, 600), nrow = 2)
newnum.mtrx <- num.mtrx / 10
newnum.mtrx * 20

#add to existing matrix
sum <- colSums(exmtrx)
average <- colMeans(exmtrx)
exmtrx.prelim <- rbind(exmtrx, sum, average)
exmtrx.prelim

#swap rows of matrices
mtrx1 <- matrix(c(1:12), nrow = 3)
mtrx2 <- matrix(c(81:100), nrow = 5)
temp <- mtrx1[2,]
mtrx1[2, ] <- mtrx2[2,]
mtrx2[2, ] <- temp
