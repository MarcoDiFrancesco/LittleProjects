# Linux

## Commands

`env` to get enviroment variables  
`$VAR` and `${VAR}` are the same thing, the second one allows things like `${VAR}m`.  
`${VAR:-PrintThisInCaseIsEmpty}`  
`PATH=$PATH:/home/dir` to concatenate to a string.  
`$1` to `$255`, `$@` returns all, `$?` returns code of the function (0 if well corrected), `$$` returns what is running now, `$!` returns last processes that's running in background.

`export VAR` allows the child processes to use that variable.  
`./script.sh` makes the script run in a children process, `source script.sh` makes it run in the current enviroment, so reading reviroment variables.  
Normally variables inside funtions are exported also outside the function. Local variables can be created using `local VAR`.

`exit` exit the script (like break in C)
`return` exit the function (like return in C)

---

### Shared memory

![Shared memory](https://i.imgur.com/05DtMsL.png)

![Shared memory](https://i.imgur.com/3cjTM58.png)

![Shared memory](https://i.imgur.com/3cjTM58.png)

### System calls

When making a system call, the system can return a code between 1 and 255. If the code is -1, this means that the system call failed. System call fail means that the system wasn't able to execute the call, not that for example the proviledges were not high enough.

**We need to check every time if -1 was returned**.

System call examples:

![System call examples](https://i.imgur.com/7NTlVA8.png)
