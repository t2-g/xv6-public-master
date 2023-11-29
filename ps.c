#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main()
{   char *process_state[] = {
    [0] = "UNUSED",
    [1] =  "EMBRYO",
    [2] = "SLEEPING",
    [3] = "RUNNABLE",
    [4] ="RUNNING",
    [5] = "ZOMBIE",
};
    struct uproc *up = malloc(sizeof(struct uproc));
    for (int i = 0; i < NPROC; i++)
    {
        if (getprocinfo(i, up) == -1)
        {
            continue;
        }

        // process id
        printf(1, "The process id is %d\n", up->pid);

        // parent process id
        printf(1, "The parent process id is %d\n", up->ppid);

        // size of process
        printf(1, "The process size is %d bytes\n", up->size);
        printf(1, "The process state is %s\n", process_state[up->state]);

        // if the process is killed
        if (up->killed)
        {
            printf(1, "The process is killed\n");
        }
        else
        {
            printf(1, "The process is not killed\n");
        }

        // if the process is waiting on a channel

        if (up->channel == -1)
        {
            printf(1, "The process is not waiting on a channel\n");
        }
        else
        {
            printf(1, "The process is waiting on a channel\n");
        }

        printf(1, "\n");
    }
    exit();
}