<html>
<img src="https://apply.borntocode.co.za/assets/new_ui/logo-4149353f5a49382b60f6915c1a4e2dde.svg" alt="We Think Code" 
</body>
</html>
#WeThinkCode_   Semi-C-Library
###  For safety, recorded and trackable history of the growth of this C-library and for sharing this work and contributing back to it, we have decided to keep it here.
####   Feel free to fork the repository and use this library. Also if you would like to contribute back, push to the repository that you will have forked and do a pull request.
####    But please, test your code before commiting and pushing into your fork, because we will not merge any pull requests that will break the library or the Norme.
######Learn more about forking a repository <a href=https://help.github.com/articles/fork-a-repo/>here</a> and about pull requests <a href=https://help.github.com/articles/creating-a-pull-request/>here.</a>
######If you are completely new to the concept of version control, you might want to start <a href="https://www.youtube.com/watch?v=Y9XZQO1n_7c">here.</a> 

##How to make the library (libft.a)?
##### Assuming that you have the clone of the repository.
```C
$ cd libft/  //Go to where the library recipe is at.
$ make      //Make the library from the recipe.
```
Now ```libft.a``` must be part of the working directory.

##How to use the library (linking to a program)?
##### Assuming that you have your main.c in the libft_test directory of the repository.
```C
$ alias run='gcc -Wall -Werror -Wextra' //This could save you a lot time.
$ run ./libft_test/main.c -c -I./includes/ -L. -lft
```
###  And you're good to go!!!

###REMEMBER
####To Respect the Norme
