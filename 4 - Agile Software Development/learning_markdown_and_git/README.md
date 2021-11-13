# Tehtävä: Git Workshop - Markdown
## ILO

Using Git for co-operation, applying a collaborative workflow. Figure out the added functionalities provided by Git hosting services.

## Description
In this exercise the work group creates a collections of git tips in using the markdown format.
Each “tip” is stored in a separate file named

- “some name 1”.md
- “some name 2”.md
- ...
… where the name should describe the command or function described in the file - for example merge.md.

Create 5 files per group member.

A new GitHub repo is created for this group work and permissions set for group members. For the instructor either

- Public -  free ro permission to anyone
- Read permission to *“teacher"* GitHub account

Use the  Feature Branch Workflow for this work meaning:
- each student clones the repository
- creates a new branch
- pushes the branch
- creates pull request
- some other student reviews the pull request
original creator of the PR merges branch to main

## References
- [Markdown syntax](https://www.google.com/url?q=https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet&sa=D&source=editors&ust=1636810971083000&usg=AOvVaw2D9DFXSLwVnb5fkh0UsogJ) 
- [Git Feature Branch Workflow ](https://www.atlassian.com/git/tutorials/comparing-workflows/feature-branch-workflow) - Atlassian
- [Hello World](https://docs.github.com/en/get-started/quickstart/hello-world) - GitHub
- [Git Handbook](https://docs.github.com/en/get-started/using-git/about-git) 
- [GitHub Training & Guides](https://www.youtube.com/user/GitHubGuides) 
- [Git SCM](https://git-scm.com/)

---

# Instructions
## Getting started

There are many ways to get started. Here one possibility for bootstrapping the workshop environment:

- In GitHub:
    - Create an empty repo to GitHub (or some other Git hosting service).
    - Tune the permissions so that all group members have full access to the repo
- Locally - one member of the group initializes the common repo for the group
    - Clone the given repo to your local host
    ```
    $ git clone <template repo url>
    $ cd gittips (or whatever is the name of the repo)
    ```
    - Wipe out the .git -folder and initialize repo
    ```
    $ \rm -rf .git
    $ git init
    ```

    - Set your own GitHub repo as remote origin and push
    ```
    $ git remote add origin <repo url>
    $ push -u origin master (or main ...)
    ```
- Locally all members of the group
    - clone the workshop repo
    - ` $ git clone <group’s repo url>`
    - start developing following the workflow chosen

