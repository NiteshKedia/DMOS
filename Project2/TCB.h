#include<ucontext.h>
#include<stdio.h>
#include<string.h>
//Test comment
struct TCB{
         struct TCB *next;
         struct TCB *prev;
        ucontext_t context;
};

typedef struct TCB TCB_t;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{

	//printf("Inside Init TCB...\n");
	//printf("1\n");
	memset(tcb,'\0',sizeof(TCB_t));
	//printf("2\n");
	getcontext(&tcb->context);
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t) stack_size;
	//printf("4\n");
	makecontext(&tcb->context, function, 0);
	//printf("5\n");

}
