# Intermediate C++

## Due dates

- [x] Lab 1 due Jan 20
- [ ] Lab 2 due Jan 27
- [ ] Lab 3 due Feb 3
- [ ] Lab 4 due Feb 10
- [ ] Lab 5 due Feb 17
- [ ] Lab 6 due Feb 24
- [ ] Lab 7 due Mar 3
- [ ] Lab 8 due Mar 10
- [ ] Lab 9 due Mar 17
- [ ] Lab 10 due Mar 24
- [ ] Lab 11 due Mar 31
- [ ] Lab 12 due Apr 7
- [ ] Lab 13 due Apr 14
- [ ] Lab 14 due Apr 21
- [x] Assignment 1 due Feb 19
- [ ] Assignment 2 due March 26
- [ ] Assignment 3 due April 23
- [ ] Test 1 due February 22
- [ ] Test 2 due March 29
- [ ] Test 3 due April 26 

## GPG key setup
### Set all commits to use GPG signing
``` 
git config --global commit.gpgsign true
```
### Create GPG key
```  
gpg --gen-key
```
You will be prompted for your name and email, make sure to use the one you configured in git. To check your configuration:
```
git config --global --get-regexp user..
``` 
### Config git
```
git config --global user.signingkey HEXKEYGOESHERE
git config --global commit.gpgsign true
```
### Config github

#### Show git logs:  
```
git log --show-signature
```
#### Get GPG key
```
gpg --armor --export HEXKEYGOESHERE
```
#### Add it to github
![alt text](https://github.com/[username]/[reponame]/blob/[branch]/image.jpg?raw=true)


