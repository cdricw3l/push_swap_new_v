#include "generateur.h"

int exec_all_list(char *line, int line_nb)
{
    pid_t pid1;
    pid_t pid2;
    int tube[2];
    int status;

    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork:");
        return (ERR);
    }
    if(pid1 == 0)
    {
        if(pipe(tube) < 0)
        {
            perror("fork:");
            exit(1);
        }
        pid2 = fork();
        if (pid2 < 0)
        {
            perror("fork:");
            return (ERR);
        }
        if (pid2 == 0)
        {
            

            // close(tube[0]);
            
            // dup2(tube[1], STDOUT_FILENO);
            // close(tube[1]);
            char *arg[] = {"push_swap", "--medium", line, NULL};
            if(execve("../push_swap", arg, NULL) < 0)
            {
                perror("Excve:");
                exit(1);
            }
        }
        else
        {
            // close(tube[1]);
            // dup2(tube[0],STDIN_FILENO);
            // close(tube[0]);
            // if(waitpid(pid1, &status, 0) < 0)
            // {
            //     perror("Wait:");
            //     return (1);
            // }
            // char *arg[] = {"wc", "-l", NULL};
            // if(execve("/usr/bin/wc", arg, NULL) < 0)
            // {
            //     perror("Excve:");
            //     exit(1);
            // }
        }
    }
    else
    {   
        if(waitpid(pid1, &status, 0) < 0)
        {
            perror("Wait:");
            return (1);
        }
        if (!WIFEXITED(status))
        {
            printf("Error %d\n", WEXITSTATUS(status));
            return (ERR);
        }
    }
    return (OK);
}

int main(void)
{
    char *line;
    int fd;
    int i;

    fd = open("generateur/test_liste_2.txt", O_RDONLY);
    if(fd < 0)
    {
        perror("open:");
        return (1);
    }
    i = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        //printf("Exectution: %d line: %s\n", i, line);
        if(!line)
        {
            close(fd);
            return (1);
        }
        line[ft_strlen(line) - 1] = 0;
        if(line)
            assert(exec_all_list(line, i) == OK);
        free(line);
        i++;
    }
    return (0);
}