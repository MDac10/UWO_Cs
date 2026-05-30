##Assignment 3

library("tidyverse")
library(ggplot2)

path <- "C:\\Users\\megda\\OneDrive\\Documents\\Projects\\MBI4850\\landdata-states.csv"

my.df <- read.csv(file=path)

my.df$State <- as.factor(my.df$State)
my.df$region <- as.factor(my.df$region)
my.df$Qrtr <- as.factor(my.df$Qrtr)

my.hist <- ggplot(data = my.df, aes(x = Home.Value)) + geom_histogram(binwidth = 2000, color = "orange", fill = "grey", alpha = 0.2) + labs(title = "Home Value Distribution", x = "Home Values", y = "Frequency") + coord_cartesian(xlim = c(20000,80000))
stacked.bar <- ggplot(data = my.df, aes(x = region, fill = Qrtr)) + geom_bar() + labs(title = "Home Counts by Quarter", x = "Regions", y = "Home Counts") + theme_light() + facet_wrap(~Year)
my.boxplot <- ggplot(data = my.df, aes(x = Year, y = Home.Value)) + geom_boxplot() + geom_jitter(width = 0.1, aes(color = region)) + theme_light()
flipped.box <-  my.boxplot + coord_flip()
scatter.plot <- ggplot(my.df, aes(Land.Value, Land.Share..Pct.)) + geom_point(aes(color = region), shape = 2) + theme_light()
scatter.plot2 <- ggplot(my.df, aes(Land.Value, Home.Value)) + geom_point(aes(color = Land.Value < 50000)) + facet_wrap(~region) + labs(x = "Land Value", y = "Home Value")

my.df2 <- mutate(my.df, Year.Group = factor(case_when((Year < 1990) ~ "Group-1", ((Year > 1990) & (Year < 2000))~ "Group-2",(Year > 2000) ~ "Group-3")))
my.violin <- ggplot(my.df2, aes(x = Year.Group, y = Structure.Cost)) + geom_violin() + coord_flip() + labs(title = "Structure Costs for Each Year Group", x = "Year Group", y = "Structure Cost")
