#include <stdio.h>
#include <windows.h>
#include <string.h>

struct date
{
	char producator[10];
	char model[10];
	char numar_model[10];
	char serie[10];
	int nuclee;
	int fire_executie;
	float frecventa;
	int scor_single_thread;
	int scor_multi_thread;
	float pret;
	float performanta_pret;
};
struct date proc[20], inter;

int minim()
{
	int i;
	float min=proc[0].pret;
	for(i=1;i<15;i++)
		if(min>proc[i].pret)
			min=proc[i].pret;
	return min;
}
void ordonare_scor_performanta_pret_cresc()
{
	int i, j;
	for(i=0; i<14; i++)
		for(j=i+1; j<15; j++)
		{
			if(proc[i].performanta_pret>proc[j].performanta_pret)
			{
				inter=proc[i];
				proc[i]=proc[j];
				proc[j]=inter;
			}

		}
}

void ordonare_pret_desc()
{
	int i, j;
	for(i=0; i<14; i++)
		for(j=i+1; j<15; j++)
		{
			if(proc[i].pret<proc[j].pret)
			{
				inter=proc[i];
				proc[i]=proc[j];
				proc[j]=inter;
			}

		}
}

void ordonare_pret_cresc()
{
	int i, j;
	for(i=0; i<14; i++)
		for(j=i+1; j<15; j++)
		{
			if(proc[i].pret>proc[j].pret)
			{
				inter=proc[i];
				proc[i]=proc[j];
				proc[j]=inter;
			}

		}
}

void ordonare_frecventa_desc()
{
	int i, j;
	for(i=0; i<14; i++)
		for(j=i+1; j<15; j++)
		{
			if(proc[i].frecventa<proc[j].frecventa)
			{
				inter=proc[i];
				proc[i]=proc[j];
				proc[j]=inter;
			}

		}
}

void ordonare_frecventa_cresc()
{
	int i, j;
	for(i=0; i<14; i++)
		for(j=i+1; j<15; j++)
		{
			if(proc[i].frecventa>proc[j].frecventa)
			{
				inter=proc[i];
				proc[i]=proc[j];
				proc[j]=inter;
			}

		}
}

int main(int argc, char** argv)
{
	int n, i;
	float buget, minn;
	FILE *f2;
	f2 = fopen("ordonare_desc_pret.txt","w");
	FILE *f1;
	f1 = fopen("procesoare.txt","r");
	fscanf(f1,"%d",&n);
	char tip[15], raspuns1[15], raspuns2[15], raspuns3[15];
	printf("Numarul de procesoare: %d\n",n);
	fflush(stdout);

	for(i=0; i<n; i++)
	{
		fscanf(f1,"%s",proc[i].producator);
		fscanf(f1,"%s",proc[i].model);
		fscanf(f1,"%s",proc[i].numar_model);
		fscanf(f1,"%s",proc[i].serie);
		fscanf(f1,"%d",&proc[i].nuclee);
		fscanf(f1,"%d",&proc[i].fire_executie);
		fscanf(f1,"%f",&proc[i].frecventa);
		fscanf(f1,"%d",&proc[i].scor_single_thread);
		fscanf(f1,"%d",&proc[i].scor_multi_thread);
		fscanf(f1,"%f",&proc[i].pret);
		fscanf(f1,"%f",&proc[i].performanta_pret);
	}

	printf("Lista cuprinde urmatoarele procesoare: \n");
	fflush(stdout);
	for(i=0; i<n; i++)
	{
		printf("%9s ",proc[i].producator);
		fflush(stdout);
		printf("%9s ",proc[i].model);
		fflush(stdout);
		printf("%9s ",proc[i].numar_model);
		fflush(stdout);
		printf("%9s  ",proc[i].serie);
		fflush(stdout);
		printf("nuclee: %2d   ",proc[i].nuclee);
		fflush(stdout);
		printf("fire de executie: %2d   ",proc[i].fire_executie);
		fflush(stdout);
		printf("Frecventa: %.1f GHz  ",proc[i].frecventa);
		fflush(stdout);
		printf("pret: $%.2f\n",proc[i].pret);
		fflush(stdout);
	}

	printf("\nLa ce tip de sistem se utilizeaza procesorul (gaming/workstation)?");
	fflush(stdout);
	scanf("%s", tip);

do
{
	if((strcmp(tip,"gaming")!=0) && (strcmp(tip,"workstation")!=0))
	{
		printf("Categoria introdusa nu a fost gasita! Introduceti gaming/workstation \n");
		fflush(stdout);
		scanf("%s", tip);
	}
	if(strcmp(tip,"gaming")==0)
	{
		printf("Pentru un sistem de tip gaming sunt recomandate urmatoarele procesoare: \n");
		fflush(stdout);
				for(i=0; i<n; i++)
					if((proc[i].scor_single_thread>2900) && (proc[i].nuclee>=6)){
						printf("%s %s %s %s\n", proc[i].producator,proc[i].model,proc[i].numar_model,proc[i].serie);
						fflush(stdout);}

	}
	if(strcmp(tip,"workstation")==0)
	{
		printf("Pentru un sistem de tip workstation sunt recomandate urmatoarele procesoare: \n");
		fflush(stdout);
				for(i=0; i<n; i++)
					if(proc[i].scor_multi_thread>16000){
						printf("%s %s %s %s\n", proc[i].producator,proc[i].model,proc[i].numar_model,proc[i].serie);
						fflush(stdout);}
	}
}while((strcmp(tip,"gaming")!=0) && (strcmp(tip,"workstation")!=0));

ordonare_pret_desc();
fprintf(f2,"Ordonarea descrescatoare a procesoarelor in functie de pret ($): \n\n");
for(i=0;i<n;i++)
{
	fprintf(f2,"%s ",proc[i].producator);
	fprintf(f2,"%s ",proc[i].model);
	fprintf(f2,"%s ",proc[i].numar_model);
	fprintf(f2,"%s ",proc[i].serie);
	fprintf(f2,"\nNuclee: %d ",proc[i].nuclee);
	fprintf(f2,"\nFire de executie: %d ",proc[i].fire_executie);
	fprintf(f2,"\nFrecventa: %.1f GHz ",proc[i].frecventa);
	fprintf(f2,"\nScor single thread conform PassMark: %d ",proc[i].scor_single_thread);
	fprintf(f2,"\nScor multi thread conform PassMark: %d ",proc[i].scor_multi_thread);
	fprintf(f2,"\nPretul: $%.2f ",proc[i].pret);
	fprintf(f2,"\nScorul performanta/pret conform PassMark: %.2f\n\n",proc[i].performanta_pret);
}

	printf("Doriti o ordonare a procesoarelor in functie de frecventa/pret? (da/nu) \n");
	fflush(stdout);
	scanf("%s", raspuns1);

do
{

	if((strcmp(raspuns1,"da")!=0) && (strcmp(raspuns1,"nu")!=0))
	{
		printf("Introduceti 'da' sau 'nu'. \n");
		fflush(stdout);
		scanf("%s", raspuns1);
	}

	if(strcmp(raspuns1,"da")==0)
	{
		printf("Doriti o ordonare in functie de frecventa sau in functie de pret? (frecventa/pret) \n");
		fflush(stdout);
		scanf("%s", raspuns2);
		do
		{

			if((strcmp(raspuns2,"frecventa")!=0) && (strcmp(raspuns2,"pret")!=0))
			{
				printf("Introduceti 'frecventa' sau 'pret'. \n");
				fflush(stdout);
				scanf("%s", raspuns2);
			}

			if(strcmp(raspuns2,"frecventa")==0)
			{
				printf("crescator/descrescator? \n");
				fflush(stdout);
				scanf("%s", raspuns3);
				do
				{

					if((strcmp(raspuns3,"crescator")!=0) && (strcmp(raspuns3,"descrescator")!=0))
					{
						printf("Introduceti 'crescator' sau 'descrescator'. \n");
						fflush(stdout);
						scanf("%s", raspuns3);
					}

					if(strcmp(raspuns3,"crescator")==0)
					{
						printf("Procesoarele ordonate crescator in functie de frecventa:\n");
						fflush(stdout);
						ordonare_frecventa_cresc();
					}

					if(strcmp(raspuns3,"descrescator")==0)
					{
						printf("Procesoarele ordonate descrescator in functie de frecventa:\n");
						fflush(stdout);
						ordonare_frecventa_desc();
					}

				}while((strcmp(raspuns3,"crescator")!=0) && (strcmp(raspuns3,"descrescator")!=0));
			}

			if(strcmp(raspuns2,"pret")==0)
			{
				printf("crescator/descrescator? \n");
				fflush(stdout);
				scanf("%s", raspuns3);
				do
				{

					if((strcmp(raspuns3,"crescator")!=0) && (strcmp(raspuns3,"descrescator")!=0))
					{
						printf("Introduceti 'crescator' sau 'descrescator'. \n");
						fflush(stdout);
						scanf("%s", raspuns3);
					}

					if(strcmp(raspuns3,"crescator")==0)
					{
						printf("Procesoarele ordonate crescator in functie de pret:\n");
						fflush(stdout);
						ordonare_pret_cresc();
					}

					if(strcmp(raspuns3,"descrescator")==0)
					{
						printf("Procesoarele ordonate descrescator in functie de pret:\n");
						fflush(stdout);
						ordonare_pret_desc();
					}

				}while((strcmp(raspuns3,"crescator")!=0) && (strcmp(raspuns3,"descrescator")!=0));

			}

		}while((strcmp(raspuns2,"frecventa")!=0) && (strcmp(raspuns2,"pret")!=0));
	}

	if(strcmp(raspuns1,"nu")==0)
		break;

}while((strcmp(raspuns1,"nu")!=0) && (strcmp(raspuns1,"da")!=0));

if(strcmp(raspuns1,"nu")==0)
{
	ordonare_scor_performanta_pret_cresc();
	printf("Procesoarele ordonate in functie de scorul performanta-pret, conform PassMark:\n");
	fflush(stdout);
	for(i=0; i<n; i++)
	{
		printf("%9s ",proc[i].producator);
		fflush(stdout);
		printf("%9s ",proc[i].model);
		fflush(stdout);
		printf("%9s ",proc[i].numar_model);
		fflush(stdout);
		printf("%9s  ",proc[i].serie);
		fflush(stdout);
		printf("nuclee: %2d   ",proc[i].nuclee);
		fflush(stdout);
		printf("fire de executie: %2d   ",proc[i].fire_executie);
		fflush(stdout);
		printf("Frecventa: %.1f GHz  ",proc[i].frecventa);
		fflush(stdout);
		printf("pret: $%.2f\n",proc[i].pret);
		fflush(stdout);
	}
}
else
{
	for(i=0; i<n; i++)
	{
		printf("%9s ",proc[i].producator);
		fflush(stdout);
		printf("%9s ",proc[i].model);
		fflush(stdout);
		printf("%9s ",proc[i].numar_model);
		fflush(stdout);
		printf("%9s  ",proc[i].serie);
		fflush(stdout);
		printf("nuclee: %2d   ",proc[i].nuclee);
		fflush(stdout);
		printf("fire de executie: %2d   ",proc[i].fire_executie);
		fflush(stdout);
		printf("Frecventa: %.1f GHz  ",proc[i].frecventa);
		fflush(stdout);
		printf("pret: $%.2f\n",proc[i].pret);
		fflush(stdout);
	}
}

minn=minim();
printf("\nIntroduceti un buget.");
fflush(stdout);
scanf("%f", &buget);

if(buget>=minn)
	{
	printf("\nIn bugetul ales se incadreaza urmatoarele procesoare:\n");
	fflush(stdout);
	}

	for(i=0; i<n; i++)
	if(buget>=proc[i].pret)
		{
		printf("%9s ",proc[i].producator);
		fflush(stdout);
		printf("%9s ",proc[i].model);
		fflush(stdout);
		printf("%9s ",proc[i].numar_model);
		fflush(stdout);
		printf("%9s  ",proc[i].serie);
		fflush(stdout);
		printf("nuclee: %2d   ",proc[i].nuclee);
		fflush(stdout);
		printf("fire de executie: %2d   ",proc[i].fire_executie);
		fflush(stdout);
		printf("Frecventa: %.1f GHz  ",proc[i].frecventa);
		fflush(stdout);
		printf("pret: $%.2f\n",proc[i].pret);
		fflush(stdout);
		}

	if(buget<minn)
	{
		printf("Nu se incadreaza nici un procesor in bugetul ales.\n");
		fflush(stdout);
	}

ordonare_scor_performanta_pret_cresc();

	fclose(f1);
	fclose(f2);
	return 0;
}
