Student Setup
-------------
The development environment is a set of tools and processes used to create programs and software. In
order to build, test, and run your programs, you will need to have a working `C++` development
environment. This document will walk you through how to set up a proper development environment on
your computer.

Normally, repositories house code that all developers use as a base to build their changes off of.
When other developers make changes, all developers pull them in and continue their work on top.
In our case, however, each student will have a separate fork of this repository in order to complete
their assignments. Furthermore, each student must keep their fork private so as to prevent any
possible plagiarism. Unfortunately, GitHub does not allow private forks of public repositories. For
this reason, we won't be using the standard GitHub workflow here. Instead, we have to jump through
some hoops in order to support our specific use case, while also using GitHub's repository hosting
platform.

Part 1: Operating System Specific Setup
---------------------------------------
Use the following instructions to properly set up your environment and your repository. The
instructions are slightly different for different operating systems.

### Mac OS X
Mac OS X doesn't come standard with a lot of the developer tools necessary to build `C++` programs
from scratch. To get these developer tools, you will have to install XCode tools on your computer.
To do so, follow the instructions below:

- Open a new terminal window
  - Press command and the space bar together to open a Spotlight Search window
  - Within Spotlight Search, type in `Terminal` and press enter once the search resolves
- Install XCode Tools
  - In the terminal window, run the command `xcode-select --install`
- Install Bazel (via [homebrew](https://brew.sh))
  - In the terminal window, run the following commands:
    ```
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    brew tap bazelbuild/tap
    brew install bazelbuild/tap/bazel
    ```

### Windows
Windows doesn't come with any of the developer tools necessary to build `C++` programs from scratch.
To get these developer tools, you will have to install a few different
programs. To do so, follow the instructions below:

- [Download](https://git-scm.com/download/win) and install `git`
  - The default settings already selected during installation are fine to use
- Install a `C++` compiler
  - Download and install the [Build Tools for Visual
    Studio](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools)
- Install Bazel
  - In a new PowerShell window, execute the following commands:
    ```
    Set-ExecutionPolicy RemoteSigned -scope CurrentUser
    iwr -useb get.scoop.sh | iex
    scoop install bazel
    ```

### Chrome OS
`C++` development on Chrome OS is currently experimental. If you have access to it, I highly
encourage you to use either Mac OS X, Windows, or Linux directly. However, if you must use Chrome
OS, follow the instructions below.

- Enable [Linux on your Chromebook](https://support.google.com/chromebook/answer/9145439)
- Open a terminal and enter the following command:
  ```
  sudo apt-get install bazel build-essential
  ```

Part 2: Bootstrap Your Repository
---------------------------------
The following instructions are independent of the operating system you are using. They apply to all
students regardless of their operating system.

- If you don't already have one, create a [GitHub](https://github.com/join) account, verify your
  email address, and sign in to your account
- [Create a new repository](https://github.com/new) on GitHub
  - Name your repository `cs900`
  - Ensure the repository is marked private
  - Create the repository
- Add `fsareshwala` as a collaborator
  - Visit the `Settings` tab
  - Select the `Manage access` section on the left
  - Click `Invite a collaborator` near the bottom of the page
  - Add the `fsareshwala` user as a collaborator to your repository
- Bootstrap your repository
  - Run the following commands in a terminal (on Windows, use gitbash)
  - **Note**: `bazel` doesn't work well with paths that have spaces in them. If your home directory
    has spaces (e.g. on Windows), you will need to place the `cs900` directory in a location without
    a space in the path (e.g. `/c/projects/cs900`).
  - **Note**: make sure to replace `username` in the last command with your GitHub username
  ```
  curl https://raw.githubusercontent.com/fsareshwala/cs900/master/tools/bootstrap.sh | bash -s username

  ```
  - You will now have a directory named `cs900` where you executed the command above. This is your
    assignment directory where you will do your work.

Part 3: Installing an IDE
-------------------------
An integrated development environment (IDE) is a tool that developers use to work on code. The IDE
includes all of the elements necessary to compile, run, and debug our programs. The IDE we will use
for this class is Visual Studio Code (VSCode).

**Note**: you are not required to use VSCode or even an IDE. You may use whatever tools you prefer
using. However, VSCode is the supported IDE for this class. If you venture off on your own, you will
be responsible for ensuring your environment works and runs programs properly.

Follow the instructions below to install and properly set up your IDE.

- [Download](https://code.visualstudio.com/Download) and install VSCode
  - **Note**: if you have a Chromebook, [use these instructions
    instead](https://www.youtube.com/watch?v=WZvEbMUMf7s)
- Open VSCode and open the extension installation page
- Search for and install the following extensions within VSCode
  - `C/C++`
  - `vscode-bazel`
- Restart VSCode
- Load your assignment repository in your IDE and ensure you can compile and run programs and tests

Part 4: Making Your First Commit
--------------------------------
Now that you have properly configured your system to build and run `C++` programs, let's start
making some changes.

- Identify yourself within your repository
  - Open the `name.md` file in the top level root of the repository
  - Replace the contents with your name
  - Commit the addition and push the change to GitHub
  - This is how I know who the repository belongs to
