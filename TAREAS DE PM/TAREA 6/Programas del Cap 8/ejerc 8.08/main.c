#include <stdio.h>
#include <string.h>

/* Hospital.
   El programa genera informaci�n acerca de los pacientes de un hospital. */

typedef struct {
    char cal[20];  // Calle
    int num;       // N�mero
    char col[20];  // Colonia
    char cp[6];    // C�digo Postal (debe permitir el '\0')
    char ciu[20];  // Ciudad
} domicilio;

typedef struct {
    char nom[30];   // Nombre y apellido
    int edad;
    char sexo;
    int con;        // Condici�n
    domicilio dom;
    char tel[11];   // Tel�fono (con espacio para '\0')
} paciente;

/* Prototipos de funciones */
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el n�mero de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d\n", I + 1);
        getchar();  // limpiar buffer
        printf("Nombre: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';  // quitar salto de l�nea

        printf("Edad: ");
        scanf("%d", &A[I].edad);
        getchar();

        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);
        getchar();

        printf("Condici�n (1..5): ");
        scanf("%d", &A[I].con);
        getchar();

        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = '\0';

        printf("\tN�mero: ");
        scanf("%d", &A[I].dom.num);
        getchar();

        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = '\0';

        printf("\tC�digo Postal: ");
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = '\0';

        printf("Tel�fono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = '\0';
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F': case 'f': FEM++; break;
            case 'M': case 'm': MAS++; break;
        }
    }
    int TOT = FEM + MAS;
    if (TOT > 0) {
        printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
        printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
    } else {
        printf("\nNo hay datos suficientes para calcular porcentajes.");
    }
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }
    printf("\nN�mero pacientes en condici�n 1: %d", C1);
    printf("\nN�mero pacientes en condici�n 2: %d", C2);
    printf("\nN�mero pacientes en condici�n 3: %d", C3);
    printf("\nN�mero pacientes en condici�n 4: %d", C4);
    printf("\nN�mero pacientes en condici�n 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad:\n");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("Nombre: %s\tTel�fono: %s\n", A[I].nom, A[I].tel);
        }
    }
}
