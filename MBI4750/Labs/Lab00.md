# Lab 00 - In the beginning was the command line

The practical sessions of this class will largely be run on a [virtual machine](https://en.wikipedia.org/wiki/Virtual_machine) hosted on a server being provided by Western [Science Technology Services](https://help.sci.uwo.ca/servicedesk/customer/portal/2).  This VM is running a distribution of Linux called [Ubuntu](https://en.wikipedia.org/wiki/Ubuntu).  


## Completing your assignments

To submit your assignment for this practical, you need to download a copy of this file to your own laptop or Genlab Windows machine and open it in a text editor.  The format of this text file is [Markdown](https://en.wikipedia.org/wiki/Markdown) and you should preserve all of the symbols that are used to annotate text with different type face and format commands.  Thus, I strongly recommend using a text editor that recognizes the Markdown format, such as [Typora](https://typora.io/), [VSCodium](https://vscodium.com/), or even [RStudio](https://posit.co/).

To submit the assignment, upload your copy of the Markdown file to OWL.


### Markdown

Markdown is a [markup language](https://en.wikipedia.org/wiki/Markup_language) - that is, a plain text document that includes some special notation that represents additional information for the computer.  For example, HTML is a markup language (the letters stand for HyperText Markup Language) where enclosing text within the tags `<i>` and `</i>` tell your web browser that the enclosed content should be rendered in an *italic* typeface.  [Markdown](https://en.wikipedia.org/wiki/Markdown) is much simpler to write than HTML, but as a result it is also less versatile.  A text file is given the extension `.md` to indicate to the operating system that it is formatted as a Markdown document.  

Rendering a Markdown document requires that you open the document in an application that can interpret this markup language.  There are many web apps that can interpret Markdown documents, including [GitHub](http://github.com).  There are several open source cross-platform Markdown editor that you can run on your own computer:
* [Typora](https://typora.io/)
* [Dillinger](https://dillinger.io/)
* [Atom](https://atom.io/)


#### Why is it useful to learn Markdown?

* It is a popular format for writing documentation files in open source packages, such as `README.md`, so you will often encounter Markdown-formatted files when using bioinformatic software.

* It is a good introduction for beginners to learn about following the rules of a computing language.  Markdown has a limited set of "commands", and you can see how mistakes in your Markdown format cause the incorrect rendering of the document.

* It provides a simple format for writing documents that would otherwise require a more complicated language.  For example, the program `pandoc` can convert Markdown into a variety of other file formats such as MS Word, HTML or PDF.  [R Markdown](https://rmarkdown.rstudio.com/) is an extension of Markdown that enables users to embed R code into their text documents.  [Jekyll](https://jekyllrb.com/) is a program that can generate a website by converting Markdown files into HTML documents.


#### Markdown tutorial:

* Enclosing text in single asterisks renders it in italics: `*magenta*` becomes *magenta*

* Enclosing text in double asterisks renders it in bold: `**cyan**` becomes **cyan**

* Enclosing text in back ticks renders it in fixed width font, `like source code`

* Enclosing a paragraph in triple backticks ` ``` ` is used to render a block of code.  Some Markdown interpreters will use the text immediately following the first set of backticks (on the same line) as an indication of the type of markup or programming language enclosed, and apply [syntax highlighting](https://en.wikipedia.org/wiki/Syntax_highlighting) accordingly.

* Headings are prefixed with one to four hash marks, `#`, or underlined with equal signs, `=`, or hyphens, `-`, on the line immediately following

* > Block quotes can be prefixed with `>`

* Items in a bulleted list are prefixed with either `*` or `-`.

1. Items in a numbered list are prefixed with numbers, *e.g.*, `1.`

* A link ([URL](https://en.wikipedia.org/wiki/URL)) can be added in two parts, `[displayed text](URL)`

* To embed an image, you can override the displayed text component of a link: `![](URL or path to local image file)`



## Command line interface

The command line is a text-based method of issuing directives to a computer.  Today, most people interact with their computers using a [graphical user interface](https://en.wikipedia.org/wiki/Graphical_user_interface) (GUI) in which the operating system draws windows and menus that the user can "click" on with the mouse pointer or, in the case of a touch-screen device, with hand gestures.  While a GUI provides a simple and intuitive means of controlling your computer, it is inherently limited to a prescribed set of actions.  The command line interface, on the other hand, is essentially limitless because it provides low-level access to the basic programs of the operating system.  These programs can be combined together by the user to yield results of unlimited complexity.

Developing a GUI is a time-consuming process, and vastly increases the number of resources that a program must be distributed with in order to run.  For this reason, most bioinformatic software &mdash; especially the most cutting-edge methods &mdash; must be run on the command line.  The authors simply do not have the time or resources to invest in building and maintaining a GUI.  There are, of course, ways to provide a rudimentary GUI for users to run programs that must otherwise be executed on the command line, such as [Galaxy](https://usegalaxy.org/).  However, this immediately limits what one can do with the program, and prevents users from seeing what is happening "under the hood".

Working on the command line makes it easier to automate jobs, and to distribute jobs across computing resources.  Hence, it is an important skill for [remote and distributed computing](https://en.wikipedia.org/wiki/Distributed_computing), where you are running programs on another computer or multiple computers.  In this course, we will frequently make use of a remote computer (server) that is running Linux.  This is because there are many programs we need to use that cannot be run in Windows.  In addition, the server provides a single centralized location for us to install the programs required for this course, and it ensures that every student has equal access to the same computing resources.


### Logging in

You will have been given a user account that has the same username as your Western e-mail account.  To log in, follow these instructions:

* On macOS or Linux, open the **Terminal** application
* If using Windows, start SSH using the following instructions:
https://docs.microsoft.com/en-us/windows/terminal/tutorials/ssh

* type `ssh <your UWO user ID>@compute.biology.uwo.ca` (NB: you need to replace `<anything like this>` with a different value)
* You will probably see something like this:
  ```
  The authenticity of host 'mimm4750g.sci.uwo.ca (129.100.22.52)' can't be established.
  ECDSA key fingerprint is SHA256:d9RDdozT6/WWsq/+oz... [omitted].
  Are you sure you want to continue connecting (yes/no/[fingerprint])?
  ```
  Type `yes` and hit enter.
* Enter your UWO password.  You won't see what you type for security reasons.


If you've successfully logged into the VM, you should now see something like this:
```console
art@Kestrel:~/git/mimm4750g$ ssh apoon42@compute.biology.uwo.ca
apoon42@compute.biology.uwo.ca's password: 
Welcome to Ubuntu 20.04.4 LTS (GNU/Linux 5.4.0-132-generic x86_64)
Last login: Fri Jan  6 10:08:27 2023 from 70.51.235.50
apoon42@compute:~$
```

The `$` is the [prompt](https://en.wikipedia.org/wiki/Command-line_interface#Command_prompt).  It indicates where the commands that you type will be [echoed](https://en.wikipedia.org/wiki/Echo_(computing)) after they have been transmitted from your computer over the network to the VM, and back to your computer.  By default, the prompt is preceded by some useful information.  `apoon42` is my username.  Sometimes I need to switch user accounts, so this is a reminder of which account I am using to access the VM.  `compute` is the VM's hostname.  Since I access multiple machines, this reminds me which one I am interfacing with.  Finally, the `~` symbol represents my home folder.  It is your default location in the filesystem when you log in.


### Running commands

A command is the action of running a program by submitting the name of the program to the operating system.
This program name can followed by one or more *arguments* (keywords that modify the behaviour of the program when it is being run).


#### Command line interface

Run a command (in the example below, I'm omitting the informative portion of the prompt for brevity.).  Type the following:
   ```console
   $ cowsay moo
   ```
   Try changing the argument (`moo`) to some other text and see what happens!  (Hint: if your message contains spaces, you should enclose it in quotes, e.g., `"`).


Now try this:
```console
$ cowsay -h
```
The `-h` option is generally used to ask for help text.  This output gives a version number, author and a list of commands, but it is otherwise not terribly helpful.  For some more information, we need to access the program's manual.  We can do this with the `man` program:
```console
$ man cowsay
```
This launches a [terminal pager](https://en.wikipedia.org/wiki/Terminal_pager) program to view the contexts of the text file that contains the manual for `cowsay`.  You will need to refer to this manual in order to do this exercise.  Use the arrow keys to scroll up and down in the terminal pager.  To **exit** the pager, type `q`.



Now run a different program called `fortune`.  (UNIX people tended to have a unique sense of humour.)

After you've tried this program out a few times, let's learn about [piping](https://en.wikipedia.org/wiki/Pipeline_(Unix)) with the `|` symbol, which is called a "pipe".  This symbol means that the output of the command to the left of the pipe is passed as input to the program named to the right of the pipe.  

Run the following and note the result:
```console
$ fortune | cowsay
```


## Working with files

One of the core philosophies of UNIX is that [everything is a file](https://en.wikipedia.org/wiki/Everything_is_a_file).  Programs are files, and the inputs and outputs of programs are also files.  A key difference between these types of files is that programs are files meant for the computer to read, whereas inputs and outputs are usually meant for people to read.  Consequently, program files are written in [binary](https://en.wikipedia.org/wiki/Binary_file) and input/output files are written in plain text.  


Let's create a plain text file to work with:
```console
$ fortune -l -n1000 > plain.txt
```
(We're setting some options to make sure the output is long.)  The `>` operator is telling the computer to take the output of `fortune` and redirect it to a new text file that I've uncreatively called `plain.txt`.

Let's bring up the contents of our current directory with the `ls` program.  Note your directory listing will look different:
```console
[apoon42@compute ~]$ ls
beast-mcmc  errors.log  git  messages.log  plain.txt
```


You should see a sequence of characters (string) on the left side that looks something like this: `-rw-rw-r--`.  The first character indicates whether the file is a directory (`d`, and otherwise `-`).  The remaining 9 characters are interpreted in groups of 3 - they indicate who has permissions to read (`r`), write (`w`) and execute (`x`) the file.  The first 3 permissions belong to the *owner* of the file, which is also indicated in this long listing in the third column.


Use the `cat`, `head`, `tail`, `more` and `less` programs to view the contents of `plain.txt`.  (Hint: you might need to use `q` to exit a terminal pager mode.)  

You can delete a file using the `rm` command.  **This is not reversible.  Once you delete a file in UNIX, it is gone forever!**

To create a new directory, use the command `cd`.  You can remove an empty directory using the command `rmdir`.

### Navigating the filesystem

In UNIX-like systems, files are grouped into directories, which in turn are organized in a hierarchical (tree-like) [structure](https://en.wikipedia.org/wiki/Unix_filesystem).

* The base of this hierarchical filesystem is the *root*.
* The location of a file in the filesystem is specified by a *path*.
* An *absolute path* gives the sequence of directories between the root and the file or directory.
  You can think of the path as a set of instructions for climbing a tree from its base (root) to one of the leaves (it's a very sturdy tree).
* A *relative path* is a set of instructions for climbing up or down a tree from one location to another.

Run the command `which cowsay` and copy the result here:
```console

```
This is an absolute [path](https://en.wikipedia.org/wiki/Path_(computing)) that specifies the location of this program in the filesystem.


To change locations in the filesystem, you need to use the `cd` (change directory) program.  If you enter `cd` by itself, then you switch back to your default (home) location.  To find out what this is, type `cd; pwd` and record the result below:
```console

```
(The semi-colon separates commands.  You can also hit `return` after `cd` and then type `pwd` to get the same result.)


Let's use `cd` to move from your home directory and then use `cd ..` to move your location up one directory at a time.  You should arrive at the root (`/`) in two steps.  Copy the output of `ls` for the root directory here:
```console

```

Next, use `cd <directory name>` to step down to the location of the `cowsay` program file.  When you reach the correct location, generate a long-listing of the cowsay file using the command `ls -l cowsay`.



When you are finished working on the remote server, close your session with the command `logout`.