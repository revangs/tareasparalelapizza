/* Nombre : Ruben Gazitua
  Tarea 3 Ayudantia piza*/
  
/* Para mi: recuerda preguntar bien sobre makefile, no supiste correr la tarea fuera del fork del profe */  

#include<mpi.h>
#include<stdio.h>

int* create_sub_vec(int begin, int end, int* origin);
float sub_prom(int *sub_vec2,int len_vec);
void punto1(int array[]);


int main(void){

  int comm_sz;
  int my_rank;

  int vec[100000];
  int* sub_vec = NULL;
  int n_over_p;
  punto1(vec);
  float prom;
  float prom2;
  float prom_total;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


  n_over_p = 100000/comm_sz;
  /*printf("Process %d calcula n_over_p = %d\n", my_rank, n_over_p);*/


    if (my_rank != 0) {
        sub_vec = (int*)malloc(n_over_p * sizeof(int));
        MPI_Recv(sub_vec, n_over_p, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        prom=sub_prom(sub_vec,n_over_p);
        MPI_Send(&prom,1,MPI_FLOAT,0,0,MPI_COMM_WORLD);


    } else {

        printf("Distribuyendo datos\n");
        for (int i = 1; i < comm_sz; i++) {
            sub_vec = create_sub_vec(i*n_over_p, (i*n_over_p)+n_over_p, vec);
            MPI_Send(sub_vec, n_over_p, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
        }
        sub_vec = create_sub_vec(0, n_over_p, vec);
        prom2 = sub_prom(sub_vec,n_over_p);
        for(int i = 1; i < comm_sz; i++) {
                prom=prom;
                MPI_Recv(&prom,1,MPI_FLOAT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                std::cout << "Subpromedio proceso " << i << ": " << prom << std::endl;
                prom2 += prom;
        }
        prom_total=(prom2/comm_sz);
        printf("Promedio del vector %f\n", prom_total);


    }

    MPI_Finalize();
    return 0;

}

void punto1(int array[]){ /*Llenar array con random de tarea2*/
	int b;
	int random;
	srand(time(NULL));
	for (b=0;b<100000;b++){
		random=rand()%100;
		array[b]=random;
	}
}


int* create_sub_vec(int begin, int end, int* origin){ /*paralela 2019*/
    int* sub_vec;
    int size;
    int aux = 0;
    size = end - begin;
    sub_vec = (int*)malloc(size * sizeof(int));
    for (int i = begin; i < end; ++i) {
        *(sub_vec+aux) = *(origin+i);
        aux += 1;
    }
    return  sub_vec;
}

float sub_prom(int *sub_vec2,int len_vec){
  float prom2;
  int *puntero=sub_vec2;
  float sum;
  for (int i=0; i < len_vec;i++) {
      sum+= *puntero;
      puntero++;
  }
  prom2=sum/len_vec;
  return prom2;
}
