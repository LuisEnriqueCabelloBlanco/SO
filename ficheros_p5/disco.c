#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CAPACITY 5
#define VIPSTR(vip) ((vip) ? "  vip  " : "not vip")

struct cliente{
	int id;
	int isVip;
};

void enter_normal_client(int id)
{

}

void enter_vip_client(int id)
{

}

void dance(int id, int isvip)
{
	printf("Client %2d (%s) dancing in disco\n", id, VIPSTR(isvip));
	sleep((rand() % 3) + 1);
}

void disco_exit(int id, int isvip)
{

}

void *client(void *arg)
{
	struct cliente* c = arg;
	if(c->isVip)
		enter_vip_client(c->id);
	else
		enter_normal_client(c->id);
	dance(c->id,c->isVip);
	disco_exit(c->id,c->isVip);
}

int main(int argc, char *argv[])
{
	int numCli =0;

	FILE* file = fopen(argv[1],"r");

	fscanf(file,"%d",&numCli);
	int aux;
	for(int i = 0; i< numCli;i++)
	{
		fscanf(file,"%d",&aux);
		struct cliente cli;
		cli.id = i;
		cli.isVip = aux;
	}

	return 0;
}
