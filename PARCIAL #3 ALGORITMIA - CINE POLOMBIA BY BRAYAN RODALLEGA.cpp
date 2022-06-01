#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<locale.h>
#include<windows.h>

using namespace std;

ofstream entrada;
ifstream salida;

struct Datos
{
	int ocupacion,fila,columna,piso,sala,horas;
	string TipoDocumento,Nombre,Apellido,FechaNacimiento,Direccion,Telefono,TipoR;
	long long int NDocumento,ValorPagar;
}S2DS1P1[15][15],S2DS2P1[15][15],S2DS1P2[15][15],S2DS2P2[15][15],S2DS3P2[15][15],S2DS4P2[15][15],S3DS1P3[15][15],
S3DS2P3[15][15],S3DS3P3[15][15],S3DS4P3[15][15],S4DS1P4[30][30],S4DS2P4[30][30],Cancelaciones[4050],Reservas[4050],aux;

string tdoc,name,apel,naci,dir,tel,tipor;
int ocup,fil,col,pis,sal,hora;
long long int ndoc,pago;

int Precio2D = 15000, Precio3D = Precio2D*0.40+Precio2D, Precio4D = Precio2D*0.80+Precio2D, PrecioEvento = 1000000;
int cont=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0,cont7=0,cont8=0,cont9=0,cont10=0,cont11=0,cont12=0;
int band = 0, band2 = 0;
int siguiente, k=0;
char opcl;

void BarraProgreso();
void CancelarR();
void ConsDisp();
void ConsDisp2D();
void ConsDispS2DS1P1();
void ConsDispS2DS2P1();
void ConsDispS2DS1P2();
void ConsDispS2DS2P2();
void ConsDispS2DS3P2();
void ConsDispS2DS4P2();
void ConsDisp3D();
void ConsDispS3DS1P3();
void ConsDispS3DS2P3();
void ConsDispS3DS3P3();
void ConsDispS3DS4P3();
void ConsDisp4D();
void ConsDispS4DS1P4();
void ConsDispS4DS2P4();
void ConsCancelaciones();
void ConsReserva();
void ConsPrecios();
void ConsPrecio2D();
void ConsPrecio3D();
void ConsPrecio4D();
void ConsPrecioEvento();
void GuardarCancelaciones();
void GuardarDatos();
void GuardarTools();
void Menu();
void MenuSalir();
void ListaCancelaciones();
void ListaReserva();
void RecuperarCancelaciones();
void RecuperarDatos();
void RecuperarTools();
void Reserva();
void ReservaPeliculas();
void Reserva2D();
void ReservaS2DS1P1();
void ReservaS2DS2P1();
void ReservaS2DS1P2();
void ReservaS2DS2P2();
void ReservaS2DS3P2();
void ReservaS2DS4P2();
void Reserva3D();
void ReservaS3DS1P3();
void ReservaS3DS2P3();
void ReservaS3DS3P3();
void ReservaS3DS4P3();
void Reserva4D();
void ReservaS4DS1P4();
void ReservaS4DS2P4();
void ReservaEventos();
void ReservaEventoS4DS1P4();
void ReservaEventoS4DS2P4();
void Salida();
void OrdenarCedulaC();
void OrdenarCedulaR();
void OrdenarApellidoR();
void OrdenarApellidoC();
void PasarDatos();

int main()
{
	setlocale(LC_ALL,"spanish");
	
	for(int x=0;x<15;x++)
    {
        for(int y=0;y<15;y++)
        {
            S2DS1P1[x][y].ocupacion=0;
			S2DS2P1[x][y].ocupacion=0;
			S2DS1P2[x][y].ocupacion=0;
			S2DS2P2[x][y].ocupacion=0;
			S2DS3P2[x][y].ocupacion=0;
			S2DS4P2[x][y].ocupacion=0;
			S3DS1P3[x][y].ocupacion=0;
			S3DS2P3[x][y].ocupacion=0;
			S3DS3P3[x][y].ocupacion=0;
			S3DS4P3[x][y].ocupacion=0;
        }   
    }
    
	for(int x=0;x<30;x++)
    {
        for(int y=0;y<30;y++)
        {
			S4DS1P4[x][y].ocupacion=0;
			S4DS2P4[x][y].ocupacion=0;
        }   
    }
    
    for(int i=0;i<4050;i++)
	{
		Cancelaciones[i].ocupacion = 0;
	}
    
    RecuperarDatos();
    RecuperarCancelaciones();
    RecuperarTools();
        
    int opc=0;
    
	do         
    {
    	
        system("cls");
		cout<<"\n\t.:BIENVENIDO A CINE POLOMBIA:.\n";
		cout<<"\n\nEste es nuestro menu: \n\n";
        cout<<"1. Registrar Reserva \n";
        cout<<"2. Consultar Precios\n";
        cout<<"3. Consultar disponibilidad \n";
        cout<<"4. Consultar Reservas \n";
        cout<<"5. Consultar Cancelaciones \n";
        cout<<"6. Cancelar Reserva \n";
        cout<<"7. Lista de reservas\n";
        cout<<"8. Lista de cancelaciones\n";
        cout<<"9. Salir \n";
        cout<<"\nOpcion: ";
        cin>>opc;
        switch(opc)
        {
           case 1:
           		Reserva();
		   break;
           case 2:
		   		ConsPrecios();
		   break;
           case 3:
		   		ConsDisp();
		   break;
           case 4:
           		PasarDatos();
           		OrdenarCedulaR();
		   		ConsReserva();		   		
		   break;
		   case 5:
		   		OrdenarCedulaC();
		   		ConsCancelaciones();
           break;
		   case 6:
           		CancelarR();
		   break;
		   case 7:
		   		PasarDatos();
		   		OrdenarApellidoR();
		   		ListaReserva();
		   break;
		   case 8:
		   		OrdenarApellidoC();
		   		ListaCancelaciones();
		   break;
		   case 9:
		   		system("cls");
				cout<<"\n\tGracias por usar el sistema\n";
    			cout<<"\n\t\tHasta pronto!\n";
		   break;
		   default:
		   		system("cls");
				cout<<"\n\tOpcion no valida";
				
        }
        
        if(opc==9)
		{
			opcl='N';
		}
		else
		{
			cout<<"\n\nPara volver al men� principal digite una tecla... "<<endl;
    		opcl='S';
    		getch();
    	}
        
    }while (opcl == 'S');
    
	GuardarDatos();
	GuardarCancelaciones();
	GuardarTools();
    
	return (0);
}

void Reserva()
{
	int opc;
	
	do
	{
		system("cls");
   		cout<<"\n\t.:REGISTRO DE RESERVA:.\n\n";
    	cout<<"1. Registrar reserva peliculas\n";
		cout<<"2. Registrar reserva evento\n";
		cout<<"3. Ir atras";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
		 		ReservaPeliculas();
			break;
			case 2:
				ReservaEventos();
			break;
			case 3:
				
			break;	
			default:
				cout<<"\n\tOpcion no valida";
				getch();
		}
	}while((opc<1)||(opc>3));
}

void ReservaPeliculas()
{
	int opc;
	
	do
	{
		system("cls");
    	cout<<"\n\t.:RESERVA DE PELICULAS:.\n\n";
    	cout<<"\n1. Sala 2D";
    	cout<<"\n2. Sala 3D";
    	cout<<"\n3. Sala 4D\n";
    	cout<<"\n----------------------------------";
    	cout<<"\n4. Ir atras";
    	cout<<"\n5. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
		 	  	Reserva2D();
			break;
			case 2:
				Reserva3D();
			break;
			case 3:
				Reserva4D();
			break;
			case 4:
				Reserva();
			break;
			case 5:
				
			break;			
			default:
				cout<<"\n\tOpcion no valida";
				getch();
		}
	}while((opc<1)||(opc>5));
}

void Reserva2D()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\n\t.:SALAS 2D:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 1:\n";
		cout<<"\n1. 2D SALA 1 (15x15)";
		cout<<"\n2. 2D SALA 2 (15x15)";
		cout<<"\n\nPISO 2:\n";
		cout<<"\n3. 2D SALA 1 (15x15)";
		cout<<"\n4. 2D SALA 2 (15x15)";
		cout<<"\n5. 2D SALA 3 (15x15)";
		cout<<"\n6. 2D SALA 4 (15x15)";
		cout<<"\n\n----------------------------------";
		cout<<"\n7. Ir atras";
		cout<<"\n8. Ir a Reservas";
		cout<<"\n9. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				ReservaS2DS1P1();
			break;
			case 2:
				ReservaS2DS2P1();
			break;
			case 3:
				ReservaS2DS1P2();
			break;
			case 4:
				ReservaS2DS2P2();
			break;
			case 5:
				ReservaS2DS3P2();
			break;
			case 6:
				ReservaS2DS4P2();
			break;
			case 7:
				ReservaPeliculas();
			break;
			case 8:
				Reserva();
			break;
			case 9:
				
			break;		
			default:
				cout<<"\n\tOpcion no valida\n\n";
				getch();
		}
		
	}while((opc<1)||(opc>9));
	
}

void ReservaS2DS1P1()
{
	
	int f,c,opc,opc2;
	
	if(cont<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS2DS1P1();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS1P1();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS1P1();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S2DS1P1[f][c].ocupacion==0))
    			{
    				do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S2DS1P1[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S2DS1P1[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S2DS1P1[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S2DS1P1[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S2DS1P1[f][c].TipoDocumento<<": ";
    				cin>>S2DS1P1[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S2DS1P1[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S2DS1P1[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S2DS1P1[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S2DS1P1[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S2DS1P1[f][c].Telefono;
    				fflush(stdin);
    				S2DS1P1[f][c].TipoR = "PELICULA_2D";
    				S2DS1P1[f][c].fila=f;
	    			S2DS1P1[f][c].columna=c;
	    			fflush(stdin);
	    			S2DS1P1[f][c].piso=1;
	    			S2DS1P1[f][c].sala=1;
    				S2DS1P1[f][c].ValorPagar = Precio2D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S2DS1P1[f][c].ValorPagar;
	    			S2DS1P1[f][c].ocupacion=1;
	    			
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S2DS1P1[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva2D();
	}
}

void ReservaS2DS2P1()
{
	
	int f,c,opc,opc2;
	
	if(cont2<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS2DS2P1();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS2P1();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS2P1();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S2DS2P1[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S2DS2P1[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S2DS2P1[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S2DS2P1[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S2DS2P1[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S2DS2P1[f][c].TipoDocumento<<": ";
    				cin>>S2DS2P1[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S2DS2P1[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S2DS2P1[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S2DS2P1[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S2DS2P1[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S2DS2P1[f][c].Telefono;
    				fflush(stdin);
    				S2DS2P1[f][c].ValorPagar = Precio2D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S2DS2P1[f][c].ValorPagar;
    				S2DS2P1[f][c].TipoR = "PELICULA_2D";
	    			S2DS2P1[f][c].ocupacion=1;
	    			S2DS2P1[f][c].fila=f;
	    			fflush(stdin);
	    			S2DS2P1[f][c].columna=c;
	    			S2DS2P1[f][c].piso=1;
	    			S2DS2P1[f][c].sala=2;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S2DS2P1[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont2++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva2D();
	}
}

void ReservaS2DS1P2()
{
	
	int f,c,opc,opc2;
	
	if(cont3<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS2DS1P2();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS1P2();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS1P2();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S2DS1P2[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S2DS1P2[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S2DS1P2[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S2DS1P2[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S2DS1P2[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S2DS1P2[f][c].TipoDocumento<<": ";
    				cin>>S2DS1P2[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S2DS1P2[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S2DS1P2[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S2DS1P2[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S2DS1P2[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S2DS1P2[f][c].Telefono;
    				fflush(stdin);
    				S2DS1P2[f][c].ValorPagar = Precio2D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S2DS1P2[f][c].ValorPagar;
    				S2DS1P2[f][c].TipoR = "PELICULA_2D";
	    			S2DS1P2[f][c].ocupacion=1;
	    			S2DS1P2[f][c].fila=f;
	    			fflush(stdin);
	    			S2DS1P2[f][c].columna=c;
	    			S2DS1P2[f][c].piso=2;
	    			S2DS1P2[f][c].sala=1;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S2DS1P2[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont3++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva2D();
	}
}

void ReservaS2DS2P2()
{
	
	int f,c,opc,opc2;
	
	if(cont4<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS2DS2P2();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS2P2();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS2P2();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S2DS2P2[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S2DS2P2[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S2DS2P2[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S2DS2P2[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S2DS2P2[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S2DS2P2[f][c].TipoDocumento<<": ";
    				cin>>S2DS2P2[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S2DS2P2[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S2DS2P2[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S2DS2P2[f][c].FechaNacimiento;
    				fflush(stdin);
	    			cout<<"\n(Use guion bajo como espacio)";
					cout<<"\nDireccion: ";
    				cin>>S2DS2P2[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S2DS2P2[f][c].Telefono;
    				fflush(stdin);
    				S2DS2P2[f][c].ValorPagar = Precio2D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S2DS2P2[f][c].ValorPagar;
    				S2DS2P2[f][c].TipoR = "PELICULA_2D";
	    			S2DS2P2[f][c].ocupacion=1;
	    			S2DS2P2[f][c].fila=f;
	    			fflush(stdin);
	    			S2DS2P2[f][c].columna=c;
	    			S2DS2P2[f][c].piso=2;
	    			S2DS2P2[f][c].sala=2;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S2DS2P2[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont4++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva2D();
	}
}

void ReservaS2DS3P2()
{
	
	int f,c,opc,opc2;
	
	if(cont5<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS2DS3P2();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS3P2();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS3P2();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S2DS3P2[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S2DS3P2[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S2DS3P2[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S2DS3P2[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S2DS3P2[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S2DS3P2[f][c].TipoDocumento<<": ";
    				cin>>S2DS3P2[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S2DS3P2[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S2DS3P2[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S2DS3P2[f][c].FechaNacimiento;
    				fflush(stdin);
	    			cout<<"\n(Use guion bajo como espacio)";
					cout<<"\nDireccion: ";
    				cin>>S2DS3P2[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S2DS3P2[f][c].Telefono;
    				fflush(stdin);
    				S2DS3P2[f][c].ValorPagar = Precio2D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S2DS3P2[f][c].ValorPagar;
    				S2DS3P2[f][c].TipoR = "PELICULA_2D";
	    			S2DS3P2[f][c].ocupacion=1;
	    			S2DS3P2[f][c].fila=f;
	    			fflush(stdin);
	    			S2DS3P2[f][c].columna=c;
	    			S2DS3P2[f][c].piso=2;
	    			S2DS3P2[f][c].sala=3;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S2DS3P2[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont5++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva2D();
	}
}

void ReservaS2DS4P2()
{
	
	int f,c,opc,opc2;
	
	if(cont6<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS2DS4P2();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS4P2();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS2DS4P2();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S2DS4P2[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S2DS4P2[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S2DS4P2[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S2DS4P2[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S2DS4P2[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S2DS4P2[f][c].TipoDocumento<<": ";
    				cin>>S2DS4P2[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S2DS4P2[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S2DS4P2[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S2DS4P2[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S2DS4P2[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S2DS4P2[f][c].Telefono;
    				fflush(stdin);
    				S2DS4P2[f][c].ValorPagar = Precio2D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S2DS4P2[f][c].ValorPagar;
    				S2DS4P2[f][c].TipoR = "PELICULA_2D";
	    			S2DS4P2[f][c].ocupacion=1;
	    			S2DS4P2[f][c].fila=f;
	    			fflush(stdin);
	    			S2DS4P2[f][c].columna=c;
	    			S2DS4P2[f][c].piso=2;
	    			S2DS4P2[f][c].sala=4;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S2DS4P2[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont6++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva2D();
	}
}

void Reserva3D()
{
	int opc;
	do
	{
		system("cls");
		cout<<"\n\t.:SALAS 3D:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 3:\n";
		cout<<"\n1. 3D SALA 1 (15x15)";
		cout<<"\n2. 3D SALA 2 (15x15)";
		cout<<"\n3. 3D SALA 3 (15x15)";
		cout<<"\n4. 3D SALA 4 (15x15)";
		cout<<"\n\n----------------------------------";
		cout<<"\n5. Ir atras";
		cout<<"\n6. Ir a Reservas";
		cout<<"\n7. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				ReservaS3DS1P3();
			break;
			case 2:
				ReservaS3DS2P3();
			break;
			case 3:
				ReservaS3DS3P3();
			break;
			case 4:
				ReservaS3DS4P3();
			break;
			case 5:
				ReservaPeliculas();
			break;
			case 6:
				Reserva();
			break;
			case 7:
				
			break;
			default:
				cout<<"\n\tOpcion no valida\n\n";
				getch();
		}
		
	}while((opc<1)||(opc>7));
	
}

void ReservaS3DS1P3()
{
	
	int f,c,opc,opc2;
	
	if(cont7<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS3DS1P3();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS1P3();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS1P3();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S3DS1P3[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S3DS1P3[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S3DS1P3[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S3DS1P3[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S3DS1P3[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
    				fflush(stdin);
    				cout<<"\nNumero de "<<S3DS1P3[f][c].TipoDocumento<<": ";
    				cin>>S3DS1P3[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S3DS1P3[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S3DS1P3[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S3DS1P3[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S3DS1P3[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S3DS1P3[f][c].Telefono;
    				fflush(stdin);
    				S3DS1P3[f][c].ValorPagar = Precio3D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S3DS1P3[f][c].ValorPagar;
    				S3DS1P3[f][c].TipoR = "PELICULA_3D";
	    			S3DS1P3[f][c].ocupacion=1;
	    			S3DS1P3[f][c].fila=f;
	    			fflush(stdin);
	    			S3DS1P3[f][c].columna=c;
	    			S3DS1P3[f][c].piso=3;
	    			S3DS1P3[f][c].sala=1;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S3DS1P3[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont7++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva3D();
	}
}

void ReservaS3DS2P3()
{
	
	int f,c,opc,opc2;
	
	if(cont8<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS3DS2P3();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS2P3();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS2P3();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S3DS2P3[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S3DS2P3[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S3DS2P3[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S3DS2P3[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S3DS2P3[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
					fflush(stdin);
    				cout<<"\nNumero de "<<S3DS2P3[f][c].TipoDocumento<<": ";
    				cin>>S3DS2P3[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S3DS2P3[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S3DS2P3[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S3DS2P3[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S3DS2P3[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S3DS2P3[f][c].Telefono;
    				fflush(stdin);
    				S3DS2P3[f][c].ValorPagar = Precio3D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S3DS2P3[f][c].ValorPagar;
    				S3DS2P3[f][c].TipoR = "PELICULA_3D";
	    			S3DS2P3[f][c].ocupacion=1;
	    			S3DS2P3[f][c].fila=f;
	    			fflush(stdin);
	    			S3DS2P3[f][c].columna=c;
	    			S3DS2P3[f][c].piso=3;
	    			S3DS2P3[f][c].sala=2;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S3DS2P3[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont8++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva3D();
	}
}

void ReservaS3DS3P3()
{
	
	int f,c,opc,opc2;
	
	if(cont9<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS3DS3P3();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS3P3();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS3P3();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S3DS3P3[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S3DS3P3[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S3DS3P3[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S3DS3P3[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S3DS3P3[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
					fflush(stdin);
    				cout<<"\nNumero de "<<S3DS3P3[f][c].TipoDocumento<<": ";
    				cin>>S3DS3P3[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S3DS3P3[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S3DS3P3[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S3DS3P3[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S3DS3P3[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S3DS3P3[f][c].Telefono;
    				fflush(stdin);
    				S3DS3P3[f][c].ValorPagar = Precio3D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S3DS3P3[f][c].ValorPagar;
    				S3DS3P3[f][c].TipoR = "PELICULA_3D";
	    			S3DS3P3[f][c].ocupacion=1;
	    			S3DS3P3[f][c].fila=f;
	    			fflush(stdin);
	    			S3DS3P3[f][c].columna=c;
	    			S3DS3P3[f][c].piso=3;
	    			S3DS3P3[f][c].sala=3;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S3DS3P3[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont9++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva3D();
	}
}

void ReservaS3DS4P3()
{
	
	int f,c,opc,opc2;
	
	if(cont10<=156)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS3DS4P3();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS4P3();
  						cout<<"\n";
					}
	    		}while((f<0)||(f>14));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>14))
    				{
    					system("cls");
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-14 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					ConsDispS3DS4P3();
  						cout<<"\n";
					}
    			}while((c<0)||(c>14));
    	
    			if((S3DS4P3[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S3DS4P3[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S3DS4P3[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S3DS4P3[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S3DS4P3[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
					fflush(stdin);
    				cout<<"\nNumero de "<<S3DS4P3[f][c].TipoDocumento<<": ";
    				cin>>S3DS4P3[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S3DS4P3[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S3DS4P3[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S3DS4P3[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S3DS4P3[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S3DS4P3[f][c].Telefono;
    				fflush(stdin);
    				S3DS4P3[f][c].ValorPagar = Precio3D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S3DS4P3[f][c].ValorPagar;
    				S3DS4P3[f][c].TipoR = "PELICULA_3D";
	    			S3DS4P3[f][c].ocupacion=1;
	    			S3DS4P3[f][c].fila=f;
	    			fflush(stdin);
	    			S3DS4P3[f][c].columna=c;
	    			S3DS4P3[f][c].piso=3;
	    			S3DS4P3[f][c].sala=4;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S3DS4P3[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			
			cont10++;
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n\tLa sala esta llena\n";
		getch();
		Reserva3D();
	}
}

void Reserva4D()
{
	int opc;
	do
	{
		system("cls");
		cout<<"\n\t.:SALAS 4D:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 4:\n";
		cout<<"\n1. 4D SALA 1 (30x30)";
		cout<<"\n2. 4D SALA 2 (30x30)";
		cout<<"\n\n----------------------------------";
		cout<<"\n3. Ir atras";
		cout<<"\n4. Ir a Reservas";
		cout<<"\n5. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				ReservaS4DS1P4();
			break;
			case 2:
				ReservaS4DS2P4();
			break;
			case 3:
				ReservaPeliculas();
			break;
			case 4:
				Reserva();
			break;
			case 5:
				
			break;
			default:
				cout<<"Opcion no valida\n\n";
				getch();
		}
		
	}while((opc<1)||(opc>5));
	
}

void ReservaS4DS1P4()
{
	
	int f,c,opc,con;
	int opc2;
    
	if(cont11<=629)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS4DS1P4();
		  
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>29))
    				{
    					system("cls");
    					ConsDispS4DS1P4();
    					cout<<"------------------------------------------------------------------\n";
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-29 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					cout<<"\n";
					}
	    		}while((f<0)||(f>29));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>29))
    				{
    					system("cls");
    					ConsDispS4DS1P4();
    					cout<<"------------------------------------------------------------------\n";
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-29 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
  						cout<<"\n";
					}
    			}while((c<0)||(c>29));
    	
    			if((S4DS1P4[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S4DS1P4[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S4DS1P4[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S4DS1P4[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S4DS1P4[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
					fflush(stdin);
    				cout<<"\nNumero de "<<S4DS1P4[f][c].TipoDocumento<<": ";
    				cin>>S4DS1P4[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S4DS1P4[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S4DS1P4[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S4DS1P4[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S4DS1P4[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S4DS1P4[f][c].Telefono;
    				fflush(stdin);
    				S4DS1P4[f][c].ValorPagar = Precio4D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S4DS1P4[f][c].ValorPagar;
    				S4DS1P4[f][c].TipoR = "PELICULA_4D";
	    			S4DS1P4[f][c].ocupacion=1;
	    			S4DS1P4[f][c].fila=f;
	    			fflush(stdin);
	    			S4DS1P4[f][c].columna=c;
	    			S4DS1P4[f][c].piso=4;
	    			S4DS1P4[f][c].sala=1;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
				
		}while(opc==1);
		
		cout<<"\n\n";
		system("pause");
		if(S4DS1P4[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			cont11++;
			band = 1;
			
		}
		
	}
	else
	{
		if(band == 1)
		{
			system("cls");
			cout<<"\n\tLa sala esta llena\n";
			getch();
			Reserva4D();
		}
		if(band == 2)
		{
			system("cls");
			cout<<"\nLa sala ya fue ocupada para un evento\n";
			getch();
			Reserva4D();
		}
	}
}

void ReservaS4DS2P4()
{
	
	int f,c,opc,opc2;
	
	if(cont12<=629)
	{
		do
		{
			opc=0;
			system("cls"); 
		
			ConsDispS4DS2P4();
		  
  			cout<<"\n";
		
				do
				{
					cout<<"Escoja su puesto por favor: \n";
			
   					cout<<"fila: ";
    				cin>>f;
    				if((f<0)||(f>29))
    				{
    					system("cls");
    					ConsDispS4DS2P4();
    					cout<<"------------------------------------------------------------------\n";
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa fila debe estar en el rango de ( 0-29 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
    					cout<<"\n";
					}
	    		}while((f<0)||(f>29));
    			do
    			{
    				cout<<"columna: ";
    				cin>>c;
	    			if((c<0)||(c>29))
    				{
    					system("cls");
    					ConsDispS4DS2P4();
    					cout<<"------------------------------------------------------------------\n";
    					cout<<"\n\t\t\tERROR!!\n";
    					cout<<"\n\tLa columna debe estar en el rango de ( 0-29 )\n";
    					cout<<"\n------------------------------------------------------------------\n";
  						cout<<"\n";
					}
    			}while((c<0)||(c>29));
    	
    			if((S4DS2P4[f][c].ocupacion==0))
    			{
	    			fflush(stdin);
	    			do
    				{
	    				fflush(stdin);
	    				system("cls");
	    				cout<<"\nTipo de documento:"<<endl;
	    				cout<<"\n1. Tarjeta de identidad";
	    				cout<<"\n2. Cedula de ciudadania";
	    				cout<<"\n3. Cedula estranjera";
	    				cout<<"\n4. Tarjeta pasaporte";
	    				cout<<"\n\nOpcion: "; cin>>opc2;
	    				switch(opc2)
	    				{
	    					case 1:
	    						S4DS2P4[f][c].TipoDocumento = "T.I";
	    					break;
	    					case 2:
	    						S4DS2P4[f][c].TipoDocumento = "C.C";
	    					break;
	    					case 3:
	    						S4DS2P4[f][c].TipoDocumento = "C.E";
	    					break;
	    					case 4:
	    						S4DS2P4[f][c].TipoDocumento = "T.P";
	    					break;
	    					default:
	    						cout<<"Opcion no valida";
	    						getch();
						}
					}while((opc2<1)||(opc2>4));
					fflush(stdin);
    				cout<<"\nNumero de "<<S4DS2P4[f][c].TipoDocumento<<": ";
    				cin>>S4DS2P4[f][c].NDocumento;
    				fflush(stdin);
	    			cout<<"\nPrimer nombre: ";
    				cin>>S4DS2P4[f][c].Nombre;
    				fflush(stdin);
    				cout<<"\nPrimer apellido: ";
    				cin>>S4DS2P4[f][c].Apellido;
    				fflush(stdin);
    				cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    				cout<<"\nFecha de nacimiento: ";
    				cin>>S4DS2P4[f][c].FechaNacimiento;
    				fflush(stdin);
    				cout<<"\n(Use guion bajo como espacio)";
	    			cout<<"\nDireccion: ";
    				cin>>S4DS2P4[f][c].Direccion;
    				fflush(stdin);
    				cout<<"\nTelefono: ";
    				cin>>S4DS2P4[f][c].Telefono;
    				fflush(stdin);
    				S4DS2P4[f][c].ValorPagar = Precio4D;
    				fflush(stdin);
    				cout<<"\nValor a pagar: $"<<S4DS2P4[f][c].ValorPagar;
    				S4DS2P4[f][c].TipoR = "PELICULA_4D";
	    			S4DS2P4[f][c].ocupacion=1;
	    			S4DS2P4[f][c].fila=f;
	    			fflush(stdin);
	    			S4DS2P4[f][c].columna=c;
	    			S4DS2P4[f][c].piso=4;
	    			S4DS2P4[f][c].sala=2;
	    			fflush(stdin);
				}
				else
				{
					do
					{
						system("cls");
						cout<<"\n\tERROR!!\n\n";
						cout<<"El puesto esta ocupado\n";
						cout<<"\n---------------------------------\n";
					
						cout<<"\nDesea volver a intentarlo?\n\n";
						cout<<"1. Para si\n";
						cout<<"2. Para no";
						cout<<"\n\nOpcion: ";
						cin>>opc;
						switch(opc)
						{
							case 1:
							break;
							case 2:
								
							break;
							default:	
								cout<<"\n\tOpcion no valida\n";
								getch();
						}
						
					}while((opc<1)||(opc>2));
				}
		}while(opc==1);
	
		
		cout<<"\n\n";
		system("pause");
		if(S4DS2P4[f][c].ocupacion==1)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!";
			getch();
			cont12++;
			band2 = 1;
			
		}
		
	}
	else
	{
		if(band2 == 1)
		{
			system("cls");
			cout<<"\n\tLa sala esta llena\n";
			getch();
			Reserva4D();
		}
		if(band2 == 2)
		{
			system("cls");
			cout<<"\nLa sala ya fue ocupada para un evento\n";
			getch();
			Reserva4D();
		}
	}
}

void ReservaEventos()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\n\t.:RESERVA DE EVENTO:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 4:\n";
		cout<<"\n1. 4D SALA 1 (30x30)";
		cout<<"\n2. 4D SALA 2 (30x30)";
		cout<<"\n\n----------------------------------";
    	cout<<"\n3. Ir atras";
    	cout<<"\n4. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				ReservaEventoS4DS1P4();
			break;
			case 2:
				ReservaEventoS4DS2P4();
			break;
			case 3:
				Reserva();
			break;
			case 4:
				
			break;		
			default:
				cout<<"\n\tOpcion no valida\n\n";
				getch();
		}
		
	}while((opc<1)||(opc>4));
	
}

void ReservaEventoS4DS1P4()
{
	int f,c,opc,opc2;
	
	if(cont11==0)
	{
		system("cls"); 
		
		fflush(stdin);
		cout<<"\n\tRESERVA DE EVENTO\n";
		cout<<"\n4D SALA 1 (30x30)\n";
		fflush(stdin);
	    do
    	{
	 		fflush(stdin);
	 		system("cls");
	 		cout<<"\nTipo de documento:"<<endl;
	 		cout<<"\n1. Tarjeta de identidad";
	 		cout<<"\n2. Cedula de ciudadania";
	 		cout<<"\n3. Cedula estranjera";
	 		cout<<"\n4. Tarjeta pasaporte";
	 		cout<<"\n\nOpcion: "; cin>>opc2;
	 		switch(opc2)
	 		{
	 			case 1:
	 				S4DS1P4[1][1].TipoDocumento = "T.I";
	 			break;
	 			case 2:
	 				S4DS1P4[1][1].TipoDocumento = "C.C";
	 			break;
	 			case 3:
	 				S4DS1P4[1][1].TipoDocumento = "C.E";
	 			break;
	 			case 4:
	 				S4DS1P4[1][1].TipoDocumento = "T.P";
	 			break;
	 			default:
	 				cout<<"Opcion no valida";
	 				getch();
			}
		}while((opc2<1)||(opc2>4));
		fflush(stdin);
    	cout<<"\nNumero de "<<S4DS1P4[1][1].TipoDocumento<<": ";
    	cin>>S4DS1P4[1][1].NDocumento;
    	fflush(stdin);
	    cout<<"\nPrimer nombre: ";
    	cin>>S4DS1P4[1][1].Nombre;
    	fflush(stdin);
    	cout<<"\nPrimer apellido: ";
    	cin>>S4DS1P4[1][1].Apellido;
    	fflush(stdin);
    	cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    	cout<<"\nFecha de nacimiento: ";
    	cin>>S4DS1P4[1][1].FechaNacimiento;
    	fflush(stdin);
    	cout<<"\n(Use guion bajo como espacio)";
	    cout<<"\nDireccion: ";
    	cin>>S4DS1P4[1][1].Direccion;
    	fflush(stdin);
    	cout<<"\nTelefono: ";
    	cin>>S4DS1P4[1][1].Telefono;
    	fflush(stdin);
    	cout<<"\nDuracion del evento (En horas): ";
		cin>>S4DS1P4[1][1].horas;
		fflush(stdin);
		S4DS1P4[1][1].ValorPagar = PrecioEvento * S4DS1P4[1][1].horas;
		fflush(stdin);
		cout<<"\nValor a pagar: $"<<S4DS1P4[1][1].ValorPagar;
		S4DS1P4[1][1].ocupacion=2;
		S4DS1P4[1][1].fila=1;
		fflush(stdin);
		S4DS1P4[1][1].columna=1;
		S4DS1P4[1][1].piso=4;
		S4DS1P4[1][1].sala=1;
		fflush(stdin);
		
		cout<<"\n\n";
		system("pause");
		if(S4DS1P4[1][1].ocupacion==2)
		{
			fflush(stdin);
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!\n";
			S4DS1P4[1][1].TipoR = "EVENTO";
			cont11=631;
			getch();
			fflush(stdin);
			for(int x=0;x<30;x++)
    		{
        		for(int y=0;y<30;y++)
      			{
					S4DS1P4[x][y].ocupacion=3;
        		}   
    		}
    		fflush(stdin);
			S4DS1P4[1][1].ocupacion=2;
			band = 2;
			fflush(stdin);
			
		}
	}
	else
	{
		
		if(band == 1)
		{
			system("cls");
			cout<<"\nLa sala ya fue reservada para ver peliculas\n";
			getch();
			ReservaEventos();
		}
		if(band == 2)
		{
			system("cls");
			cout<<"\nLa sala esta ocupada con un evento\n";
			getch();
			ReservaEventos();
		}
	}
}

void ReservaEventoS4DS2P4()
{
	int f,c,opc,opc2;
	
	if(cont12==0)
	{
		system("cls"); 
		
		cout<<"\n\tRESERVA DE EVENTO\n";
		cout<<"\n4D SALA 2 (30x30)\n";
		fflush(stdin);
	    do
   		{
	    	fflush(stdin);
	    	system("cls");
			cout<<"\nTipo de documento:"<<endl;
	    	cout<<"\n1. Tarjeta de identidad";
	    	cout<<"\n2. Cedula de ciudadania";
	    	cout<<"\n3. Cedula estranjera";
	    	cout<<"\n4. Tarjeta pasaporte";
	    	cout<<"\n\nOpcion: "; cin>>opc2;
	    	switch(opc2)
	    	{
	    		case 1:
	    			S4DS2P4[1][1].TipoDocumento = "T.I";
	    		break;
	    		case 2:
	    			S4DS2P4[1][1].TipoDocumento = "C.C";
	    		break;
	    		case 3:
	    			S4DS2P4[1][1].TipoDocumento = "C.E";
	    		break;
	    		case 4:
	    			S4DS2P4[1][1].TipoDocumento = "T.P";
	    		break;
	    		default:
	    			cout<<"Opcion no valida";
	    			getch();
			}
		}while((opc2<1)||(opc2>4));
		fflush(stdin);
    	cout<<"\nNumero de "<<S4DS2P4[1][1].TipoDocumento<<": ";
    	cin>>S4DS2P4[1][1].NDocumento;
    	fflush(stdin);
	    cout<<"\nPrimer nombre: ";
    	cin>>S4DS2P4[1][1].Nombre;
    	fflush(stdin);
    	cout<<"\nPrimer apellido: ";
    	cin>>S4DS2P4[1][1].Apellido;
    	fflush(stdin);
    	cout<<"\nFormato de fecha: DD/MM/AA | ejemplo: (23/02/2021)";
    	cout<<"\nFecha de nacimiento: ";
    	cin>>S4DS2P4[1][1].FechaNacimiento;
    	fflush(stdin);
    	cout<<"\n(Use guion bajo como espacio)";
	    cout<<"\nDireccion: ";
    	cin>>S4DS2P4[1][1].Direccion;
    	fflush(stdin);
    	cout<<"\nTelefono: ";
    	cin>>S4DS2P4[1][1].Telefono;
    	fflush(stdin);
    	cout<<"\nDuracion del evento (En horas): ";
		cin>>S4DS2P4[1][1].horas;
		fflush(stdin);
		S4DS2P4[1][1].ValorPagar = PrecioEvento * S4DS2P4[1][1].horas;
		fflush(stdin);
		cout<<"\nValor a pagar: $"<<S4DS2P4[1][1].ValorPagar;
		S4DS2P4[1][1].ocupacion=2;
		S4DS2P4[1][1].fila=1;
		fflush(stdin);
		S4DS2P4[1][1].columna=1;
		S4DS2P4[1][1].piso=4;
		S4DS2P4[1][1].sala=2;
		fflush(stdin);

				
		cout<<"\n\n";
		system("pause");
		if(S4DS2P4[1][1].ocupacion==2)
		{
			system("cls");
			cout<<"\n\tSU REGISTRO FUE EXITOSO!\n";
			S4DS2P4[1][1].TipoR = "EVENTO";
			cont12=631;
			getch();
			for(int x=0;x<30;x++)
    		{
        		for(int y=0;y<30;y++)
      			{
					S4DS2P4[x][y].ocupacion=3;
        		}   
    		}
			S4DS2P4[1][1].ocupacion=2;
			band2 = 2;
			       
		}
	}
	else
	{
		system("cls");
		
		if(band2 == 1)
		{
			system("cls");
			cout<<"\nLa sala ya fue reservada para ver peliculas\n";
			getch();
			ReservaEventos();
		}
		if(band2 == 2)
		{
			system("cls");
			cout<<"\nLa sala esta ocupada con un evento\n";
			getch();
			ReservaEventos();
		}
	}
}

void ConsPrecios()
{
	int opc;
	
	do
	{
		system("cls");
    	cout<<"\n\t.:CONSULTAR PRECIOS:.\n\n";
    	cout<<"\n1. Sala 2D";
    	cout<<"\n2. Sala 3D";
    	cout<<"\n3. Sala 4D";
		cout<<"\n4. Alquiler para evento salas 4D";
		cout<<"\n\n----------------------------------";
		cout<<"\n5. Ir atras";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
			   	ConsPrecio2D();
			break;
			case 2:
				ConsPrecio3D();
			break;
			case 3:
				ConsPrecio4D();
			break;
			case 4:
				ConsPrecioEvento();
			break;
			case 5:
				
			break;	
			default:
				system("cls");
				cout<<"\nOpcion no valida";
		}
		
	}while((opc<1)||(opc>5));
}

void ConsPrecio2D()
{
	system("cls");
	cout<<"\n\tEl precio de las Salas 2D es de: $"<<Precio2D<<endl;
	getch();
	ConsPrecios();
}

void ConsPrecio3D()
{
	system("cls");
	cout<<"\n\tEl precio de las Salas 3D es de: $"<<Precio3D<<endl;
	getch();
	ConsPrecios();
}

void ConsPrecio4D()
{
	system("cls");
	cout<<"\n\tEl precio de las Salas 4D es de: $"<<Precio4D<<endl;
	getch();
	ConsPrecios();
}

void ConsPrecioEvento()
{
	system("cls");
	cout<<"\n\tEl precio del alquiler de una sala 4D para evento es de: $"<<PrecioEvento<<" la hora";
	getch();
	ConsPrecios();
}

void ConsDisp()
{
	int opc;
	
	system("cls");
	
	do
	{
		system("cls");
    	cout<<"\n\t.:CONSULTAR DISPONIBILIDAD:.\n\n";
    	cout<<"Eliga la sala:\n";
    	cout<<"\n1. Sala 2D";
    	cout<<"\n2. Sala 3D";
    	cout<<"\n3. Sala 4D";
    	cout<<"\n\n----------------------------------";
		cout<<"\n4. Ir atras";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
			   	ConsDisp2D();
			break;
			case 2:
				ConsDisp3D();	
			break;
			case 3:
				ConsDisp4D();
			break;
			case 4:
				
			break;	
			default:
				cout<<"\n\tOpcion no valida";
				getch();
		}
	}while((opc<1)||(opc>4));
}

void ConsDisp2D()
{
	int opc;
	do
	{
		system("cls");
		cout<<"\n\t.:SALAS 2D:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 1:\n";
		cout<<"\n1. 2D SALA 1 (15x15)";
		cout<<"\n2. 2D SALA 2 (15x15)";
		cout<<"\n\nPISO 2:\n";
		cout<<"\n3. 2D SALA 1 (15x15)";
		cout<<"\n4. 2D SALA 2 (15x15)";
		cout<<"\n5. 2D SALA 3 (15x15)";
		cout<<"\n6. 2D SALA 4 (15x15)";
		cout<<"\n\n----------------------------------";
		cout<<"\n7. Ir atras";
		cout<<"\n8. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				ConsDispS2DS1P1();
			break;
			case 2:
				ConsDispS2DS2P1();
			break;
			case 3:
				ConsDispS2DS1P2();
			break;
			case 4:
				ConsDispS2DS2P2();
			break;
			case 5:
				ConsDispS2DS3P2();
			break;
			case 6:
				ConsDispS2DS4P2();
			break;
			case 7:
				ConsDisp();
			break;
			case 8:
				
			break;		
			default:
				cout<<"\n\tOpcion no valida\n\n";
				getch();
		}
		cout<<"\nDesea volver a ver este menu?\n";
		cout<<"\n1. Para si";
		cout<<"\n2. Para no\n";
		cout<<"\nOpcion: ";
		cin>>opc;
		
	}while((opc==1));
	
}

void ConsDispS2DS1P1()
{
	system("cls");
	cout<<"\n\t\t2D SALA 1 (PRIMER PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S2DS1P1[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
  
}

void ConsDispS2DS2P1()
{
	system("cls");
	cout<<"\n\t\t2D SALA 2 (PRIMER PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S2DS2P1[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
  
}

void ConsDispS2DS1P2()
{
	system("cls");
	cout<<"\n\t\t2D SALA 1 (SEGUNDO PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S2DS1P2[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
  
}

void ConsDispS2DS2P2()
{
	system("cls");
	cout<<"\n\t\t2D SALA 2 (SEGUNDO PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S2DS2P2[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
  
}

void ConsDispS2DS3P2()
{
	system("cls");
	cout<<"\n\t\t2D SALA 3 (SEGUNDO PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S2DS3P2[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
  
}

void ConsDispS2DS4P2()
{
	system("cls");
	cout<<"\n\t\t2D SALA 4 (SEGUNDO PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S2DS4P2[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
  
}

void ConsDisp3D()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\n\t.:SALAS 3D:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 3:\n";
		cout<<"\n1. 3D SALA 1 (15x15)";
		cout<<"\n2. 3D SALA 2 (15x15)";
		cout<<"\n3. 3D SALA 3 (15x15)";
		cout<<"\n4. 3D SALA 4 (15x15)";
		cout<<"\n\n----------------------------------";
		cout<<"\n5. Ir atras";
		cout<<"\n6. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				ConsDispS3DS1P3();
			break;
			case 2:
				ConsDispS3DS2P3();
			break;
			case 3:
				ConsDispS3DS3P3();
			break;
			case 4:
				ConsDispS3DS4P3();
			break;
			case 5:
				ConsDisp();
			break;
			case 6:
				
			break;		
			default:
				cout<<"\n\tOpcion no valida\n\n";
				getch();
		}
		cout<<"\nDesea volver a ver este menu?\n";
		cout<<"\n1. Para si";
		cout<<"\n2. Para no\n";
		cout<<"\nOpcion: ";
		cin>>opc;
	}while((opc==1));
	
}

void ConsDispS3DS1P3()
{
	system("cls");
	cout<<"\n\t\t3D SALA 1 (TERCER PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S3DS1P3[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
}

void ConsDispS3DS2P3()
{
	system("cls");
	cout<<"\n\t\t3D SALA 2 (TERCER PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S3DS2P3[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
}

void ConsDispS3DS3P3()
{
	system("cls");
	cout<<"\n\t\t3D SALA 3 (TERCER PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S3DS3P3[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
}

void ConsDispS3DS4P3()
{
	system("cls");
	cout<<"\n\t\t3D SALA 4 (TERCER PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14\n\n";
        
  	for(int i=0;i<15;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<15;j++)
        {
        	cout<<S3DS4P3[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
}

void ConsDisp4D()
{
	int opc;
	
	do
	{
		system("cls");
		cout<<"\n\t.:SALAS 4D:.\n";
		cout<<"\nEscoja la sala:\n";
		cout<<"\nPISO 4:\n";
		cout<<"\n1. 4D SALA 1 (30x30)";
		cout<<"\n2. 4D SALA 2 (30x30)";
		cout<<"\n\n----------------------------------";
		cout<<"\n3. Ir atras";
		cout<<"\n4. Ir al menu principal";
		cout<<"\n\nOpcion: ";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ConsDispS4DS1P4();
			break;
			case 2:
				ConsDispS4DS2P4();
			break;
			case 3:
				ConsDisp();
			break;
			case 4:
				
			break;
			default:
				cout<<"\n\tOpcion no valida\n\n";
				getch();
		}
		
		cout<<"\nDesea volver a ver este menu?\n";
		cout<<"\n1. Para si";
		cout<<"\n2. Para no\n";
		cout<<"\nOpcion: ";
		cin>>opc;
		
	}while((opc==1));
	
	
}

void ConsDispS4DS1P4()
{
	system("cls");
	cout<<"\n\t\t\t\t\t4D SALA 1 (CUARTO PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29\n\n";
        
  	for(int i=0;i<30;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<30;j++)
        {
        	cout<<S4DS1P4[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
}

void ConsDispS4DS2P4()
{
	system("cls");
	cout<<"\n\t\t\t\t\t4D SALA 2 (CUARTO PISO)\n\n";
  	cout<<"    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29\n\n";
        
  	for(int i=0;i<30;i++)
  	{
     	cout<<i<<"   ";
          
     	for(int j=0;j<30;j++)
        {
        	cout<<S4DS2P4[i][j].ocupacion<<"   ";
        }
        cout<<"\n\n";
  	}
  
  cout<<"\n";
  system("pause");
}

void ConsCancelaciones()
{
	int primero, ultimo, medio, opc, id;
	
	do
	{	
		
		opc = 0;
		primero = 0;
    	ultimo = k-1;
       	medio=(primero+ultimo)/2;
	
		system("cls");
		cout<<"\n\t.:BUSQUEDA DE CANCELACIONES POR CEDULA:.\n\n";
		cout<<"Ingrese el numero de documento del cliente a consultar: ";
       	cin>>id;
       	fflush(stdin);
       
       	while (primero<=ultimo)
       	{
		   			
			if (Cancelaciones[medio].NDocumento<id)
			{
				primero=medio+1;
			}
			else
			{
				if(Cancelaciones[medio].NDocumento==id) 
          		{
             		if(Cancelaciones[medio].ocupacion==1)
					{
						cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
						cout<<"\nDatos:\n\n";
						cout<<"Tipo de documento: "<<Cancelaciones[medio].TipoDocumento;
    					cout<<"\nNumero de documento: "<<Cancelaciones[medio].NDocumento;
	    				cout<<"\nNombre: "<<Cancelaciones[medio].Nombre;
	    				cout<<"\nApellido: "<<Cancelaciones[medio].Apellido;
    					cout<<"\nFecha de nacimiento: "<<Cancelaciones[medio].FechaNacimiento;
		    			cout<<"\nDireccion: "<<Cancelaciones[medio].Direccion;
		    			fflush(stdin);
    					cout<<"\nTelefono: "<<Cancelaciones[medio].Telefono;
    					fflush(stdin);
    					cout<<"\n\nRESERVO "<<Cancelaciones[medio].TipoR;
    					cout<<"\nPiso: "<<Cancelaciones[medio].piso;
    					cout<<"\nSala: "<<Cancelaciones[medio].sala;
    					cout<<"\nFila: "<<Cancelaciones[medio].fila;
    					cout<<"\nColumna: "<<Cancelaciones[medio].columna;
    					cout<<"\nPago: $"<<Cancelaciones[medio].ValorPagar;
    					cout<<"\n\n";
   	 					opc = 2;
   	 					getch();
					}
					if(Cancelaciones[medio].ocupacion==2)
					{
						cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
						cout<<"\nDatos:\n\n";
						cout<<"Tipo de documento: "<<Cancelaciones[medio].TipoDocumento;
    					cout<<"\nNumero de documento: "<<Cancelaciones[medio].NDocumento;
	   	 				cout<<"\nNombre: "<<Cancelaciones[medio].Nombre;
	   	 				cout<<"\nApellido: "<<Cancelaciones[medio].Apellido;
    					cout<<"\nFecha de nacimiento: "<<Cancelaciones[medio].FechaNacimiento;
	   	 				cout<<"\nDireccion: "<<Cancelaciones[medio].Direccion;
	   		 			fflush(stdin);
    					cout<<"\nTelefono: "<<Cancelaciones[medio].Telefono;
    					fflush(stdin);
    					cout<<"\n\nRESERVO "<<Cancelaciones[medio].TipoR;
 		   				cout<<"\nPiso: "<<Cancelaciones[medio].piso;
    					cout<<"\nSala: "<<Cancelaciones[medio].sala;
    					cout<<"\nDuracion: "<<Cancelaciones[medio].horas<<" Horas";
    					cout<<"\nPago: $"<<Cancelaciones[medio].ValorPagar;
    					cout<<"\n\n";
    					opc = 2;
    					getch();
					}
					break;
				}
				else
				{	
       				ultimo = medio - 1;
       			}
			}
       		
       		medio = (primero+ultimo)/2;
       		
       }
       
       	if (primero>ultimo)
       	{
           cout<<"\nLa cedula numero "<<id<<" no se encontro\n";
           cout<<"\nDesea volver a intentarlo?\n";
		   cout<<"\n1. Para si";
		   cout<<"\n2. Para no\n";
		   cout<<"\nOpcion: ";
		   cin>>opc;
    	}
       
    }while(opc==1);
    
    
}

void ConsReserva()
{
	int primero, ultimo, medio, opc, id;
	
	do
	{	
		
		opc = 0;
		primero = 0;
    	ultimo = siguiente-1;
   	    medio=(primero+ultimo)/2;

		system("cls");
		cout<<"\n\t.:BUSQUEDA DE RESERVAS POR CEDULA:.\n\n";
		cout<<"Ingrese el numero de documento del cliente a consultar: ";
       	cin>>id;
       	fflush(stdin);
       
       	while (primero<=ultimo)
       	{
		   			
			if (Reservas[medio].NDocumento<id)
			{
				primero=medio+1;
			}
			else
			{
				if(Reservas[medio].NDocumento==id) 
          		{
             		if(Reservas[medio].ocupacion==1)
					{
						cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
						cout<<"\nDatos:\n\n";
						cout<<"Tipo de documento: "<<Reservas[medio].TipoDocumento;
    					cout<<"\nNumero de documento: "<<Reservas[medio].NDocumento;
	    				cout<<"\nNombre: "<<Reservas[medio].Nombre;
	    				cout<<"\nApellido: "<<Reservas[medio].Apellido;
    					cout<<"\nFecha de nacimiento: "<<Reservas[medio].FechaNacimiento;
		    			cout<<"\nDireccion: "<<Reservas[medio].Direccion;
		    			fflush(stdin);
    					cout<<"\nTelefono: "<<Reservas[medio].Telefono;
    					fflush(stdin);
    					cout<<"\n\nRESERVO "<<Reservas[medio].TipoR;
    					cout<<"\nPiso: "<<Reservas[medio].piso;
    					cout<<"\nSala: "<<Reservas[medio].sala;
    					cout<<"\nFila: "<<Reservas[medio].fila;
    					cout<<"\nColumna: "<<Reservas[medio].columna;
    					cout<<"\nPago: $"<<Reservas[medio].ValorPagar;
    					cout<<"\n\n";
   	 					opc = 2;
   	 					getch();
					}
					if(Reservas[medio].ocupacion==2)
					{
						cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
						cout<<"\nDatos:\n\n";
						cout<<"Tipo de documento: "<<Reservas[medio].TipoDocumento;
    					cout<<"\nNumero de documento: "<<Reservas[medio].NDocumento;
	   	 				cout<<"\nNombre: "<<Reservas[medio].Nombre;
	   	 				cout<<"\nApellido: "<<Reservas[medio].Apellido;
    					cout<<"\nFecha de nacimiento: "<<Reservas[medio].FechaNacimiento;
	   	 				cout<<"\nDireccion: "<<Reservas[medio].Direccion;
	   		 			fflush(stdin);
    					cout<<"\nTelefono: "<<Reservas[medio].Telefono;
    					fflush(stdin);
    					cout<<"\n\nRESERVO "<<Reservas[medio].TipoR;
 		   				cout<<"\nPiso: "<<Reservas[medio].piso;
    					cout<<"\nSala: "<<Reservas[medio].sala;
    					cout<<"\nDuracion: "<<Reservas[medio].horas<<" Horas";
    					cout<<"\nPago: $"<<Reservas[medio].ValorPagar;
    					cout<<"\n\n";
    					opc = 2;
    					getch();
					}
					break;
				}
				else
				{	
       				ultimo = medio - 1;
       			}
			}
       		
       		medio = (primero+ultimo)/2;
       		
       }
       
       if (primero>ultimo)
       {
           cout<<"\nLa cedula numero "<<id<<" no se encontro\n";
           cout<<"\nDesea volver a intentarlo?\n";
		   cout<<"\n1. Para si";
		   cout<<"\n2. Para no\n";
		   cout<<"\nOpcion: ";
		   cin>>opc;
       }
       
    }while(opc==1);
    
    
}

void CancelarR()
{
	int opc,opc1,opc2,opc3,opc4,opc5,opc6,opc7,opc8,opc9,opc10,opc11,opc12;
	
	fflush(stdin);
	do
	{
	system("cls");
	
	int id, cont=0;
	
	cout<<"\n\t\t.:CANCELAR RESERVA:.\n\n";
	cout<<"Ingrese el numero de documento del cliente a cancelar: ";
	cin>>id;
	fflush(stdin);
	
	for(int x=0;x<15;x++)
	{
		for(int y=0;y<15;y++)
		{
			if(id==S2DS1P1[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S2DS1P1[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S2DS1P1[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S2DS1P1[x][y].Nombre;
	    			cout<<"\nApellido: "<<S2DS1P1[x][y].Apellido;
    				cout<<"\nFecha de nacimiento: "<<S2DS1P1[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S2DS1P1[x][y].Direccion;
    				cout<<"\nTelefono: "<<S2DS1P1[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 2D";
    				cout<<"\nPiso: "<<S2DS1P1[x][y].piso;
    				cout<<"\nSala: "<<S2DS1P1[x][y].sala;
    				cout<<"\nFila: "<<S2DS1P1[x][y].fila;
    				cout<<"\nColumna: "<<S2DS1P1[x][y].columna;
    				cout<<"\nPago: $"<<S2DS1P1[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc1;
    				if((opc1<1)||(opc1>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc1<1)||(opc1>2));
				if(opc1==1)
				{
					Cancelaciones[k] = S2DS1P1[x][y];
					k++;
					S2DS1P1[x][y].TipoDocumento=' ';
					S2DS1P1[x][y].NDocumento=0;
					S2DS1P1[x][y].Nombre=' ';
					S2DS1P1[x][y].Apellido=' ';
					S2DS1P1[x][y].FechaNacimiento=' ';
					S2DS1P1[x][y].Direccion=' ';
					S2DS1P1[x][y].Telefono=' ';
					S2DS1P1[x][y].piso=0;
					S2DS1P1[x][y].sala=0;
					S2DS1P1[x][y].fila=0;
					S2DS1P1[x][y].columna=0;
					S2DS1P1[x][y].ValorPagar=0;
					S2DS1P1[x][y].ocupacion=0;
					S2DS1P1[x][y].TipoR=' ';
				}
				if(S2DS1P1[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			opc = 2;
    			cout<<endl;
    			system("pause");
    			cont++;
			}
			if(id==S2DS2P1[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S2DS2P1[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S2DS2P1[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S2DS2P1[x][y].Nombre;
	    			cout<<"\nApellido: "<<S2DS2P1[x][y].Apellido;
    				cout<<"\nFecha de nacimiento: "<<S2DS2P1[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S2DS2P1[x][y].Direccion;
    				cout<<"\nTelefono: "<<S2DS2P1[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 2D";
    				cout<<"\nPiso: "<<S2DS2P1[x][y].piso;
    				cout<<"\nSala: "<<S2DS2P1[x][y].sala;
    				cout<<"\nFila: "<<S2DS2P1[x][y].fila;
    				cout<<"\nColumna: "<<S2DS2P1[x][y].columna;
    				cout<<"\nPago: $"<<S2DS2P1[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc2;
    				if((opc2<1)||(opc2>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc2<1)||(opc2>2));
				if(opc2==1)
				{
					Cancelaciones[k] = S2DS2P1[x][y];
					k++;
					S2DS2P1[x][y].TipoDocumento=' ';
					S2DS2P1[x][y].NDocumento=0;
					S2DS2P1[x][y].Nombre=' ';
					S2DS2P1[x][y].Apellido=' ';
					S2DS2P1[x][y].FechaNacimiento=' ';
					S2DS2P1[x][y].Direccion=' ';
					S2DS2P1[x][y].Telefono=' ';
					S2DS2P1[x][y].piso=0;
					S2DS2P1[x][y].sala=0;
					S2DS2P1[x][y].fila=0;
					S2DS2P1[x][y].columna=0;
					S2DS2P1[x][y].ValorPagar=0;
					S2DS2P1[x][y].ocupacion=0;
					S2DS2P1[x][y].TipoR=' ';
				}
				if(S2DS2P1[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S2DS1P2[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S2DS1P2[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S2DS1P2[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S2DS1P2[x][y].Nombre;
	    			cout<<"\nApellido: "<<S2DS1P2[x][y].Apellido;
    				cout<<"\nFecha de nacimiento: "<<S2DS1P2[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S2DS1P2[x][y].Direccion;
    				cout<<"\nTelefono: "<<S2DS1P2[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 2D";
    				cout<<"\nPiso: "<<S2DS1P2[x][y].piso;
    				cout<<"\nSala: "<<S2DS1P2[x][y].sala;
    				cout<<"\nFila: "<<S2DS1P2[x][y].fila;
    				cout<<"\nColumna: "<<S2DS1P2[x][y].columna;
    				cout<<"\nPago: $"<<S2DS1P2[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc3;
    				if((opc3<1)||(opc3>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc3<1)||(opc3>2));
				if(opc3==1)
				{
					Cancelaciones[k] = S2DS1P2[x][y];
					k++;
					S2DS1P2[x][y].TipoDocumento=' ';
					S2DS1P2[x][y].NDocumento=0;
					S2DS1P2[x][y].Nombre=' ';
					S2DS1P2[x][y].Apellido=' ';
					S2DS1P2[x][y].FechaNacimiento=' ';
					S2DS1P2[x][y].Direccion=' ';
					S2DS1P2[x][y].Telefono=' ';
					S2DS1P2[x][y].piso=0;
					S2DS1P2[x][y].sala=0;
					S2DS1P2[x][y].fila=0;
					S2DS1P2[x][y].columna=0;
					S2DS1P2[x][y].ValorPagar=0;
					S2DS1P2[x][y].ocupacion=0;
					S2DS1P2[x][y].TipoR=' ';
				}
				if(S2DS1P2[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S2DS2P2[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S2DS2P2[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S2DS2P2[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S2DS2P2[x][y].Nombre;
	    			cout<<"\nApellido: "<<S2DS2P2[x][y].Apellido;
    				cout<<"\nFecha de nacimiento: "<<S2DS2P2[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S2DS2P2[x][y].Direccion;
    				cout<<"\nTelefono: "<<S2DS2P2[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 2D";
    				cout<<"\nPiso: "<<S2DS2P2[x][y].piso;
    				cout<<"\nSala: "<<S2DS2P2[x][y].sala;
    				cout<<"\nFila: "<<S2DS2P2[x][y].fila;
    				cout<<"\nColumna: "<<S2DS2P2[x][y].columna;
    				cout<<"\nPago: $"<<S2DS2P2[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc4;
    				if((opc4<1)||(opc4>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc4<1)||(opc4>2));
				if(opc4==1)
				{
					Cancelaciones[k] = S2DS2P2[x][y];
					k++;
					S2DS2P2[x][y].TipoDocumento=' ';
					S2DS2P2[x][y].NDocumento=0;
					S2DS2P2[x][y].Nombre=' ';
					S2DS2P2[x][y].Apellido=' ';
					S2DS2P2[x][y].FechaNacimiento=' ';
					S2DS2P2[x][y].Direccion=' ';
					S2DS2P2[x][y].Telefono=' ';
					S2DS2P2[x][y].piso=0;
					S2DS2P2[x][y].sala=0;
					S2DS2P2[x][y].fila=0;
					S2DS2P2[x][y].columna=0;
					S2DS2P2[x][y].ValorPagar=0;
					S2DS2P2[x][y].ocupacion=0;
					S2DS2P2[x][y].TipoR=' ';
				}
				if(S2DS2P2[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S2DS3P2[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S2DS3P2[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S2DS3P2[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S2DS3P2[x][y].Nombre;
	    			cout<<"\nApellido: "<<S2DS3P2[x][y].Apellido;
    				cout<<"\nFecha de nacimiento: "<<S2DS3P2[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S2DS3P2[x][y].Direccion;
    				cout<<"\nTelefono: "<<S2DS3P2[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 2D";
    				cout<<"\nPiso: "<<S2DS3P2[x][y].piso;
    				cout<<"\nSala: "<<S2DS3P2[x][y].sala;
    				cout<<"\nFila: "<<S2DS3P2[x][y].fila;
    				cout<<"\nColumna: "<<S2DS3P2[x][y].columna;
    				cout<<"\nPago: $"<<S2DS3P2[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc5;
    				if((opc5<1)||(opc5>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc5<1)||(opc5>2));
				if(opc5==1)
				{
					Cancelaciones[k] = S2DS3P2[x][y];
					k++;
					S2DS3P2[x][y].TipoDocumento=' ';
					S2DS3P2[x][y].NDocumento=0;
					S2DS3P2[x][y].Nombre=' ';
					S2DS3P2[x][y].Apellido=' ';
					S2DS3P2[x][y].FechaNacimiento=' ';
					S2DS3P2[x][y].Direccion=' ';
					S2DS3P2[x][y].Telefono=' ';
					S2DS3P2[x][y].piso=0;
					S2DS3P2[x][y].sala=0;
					S2DS3P2[x][y].fila=0;
					S2DS3P2[x][y].columna=0;
					S2DS3P2[x][y].ValorPagar=0;
					S2DS3P2[x][y].ocupacion=0;
					S2DS3P2[x][y].TipoR=' ';
				}
				if(S2DS3P2[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S2DS4P2[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S2DS4P2[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S2DS4P2[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S2DS4P2[x][y].Nombre;
	    			cout<<"\nApellido: "<<S2DS4P2[x][y].Apellido;
    				cout<<"\nFecha de nacimiento: "<<S2DS4P2[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S2DS4P2[x][y].Direccion;
    				cout<<"\nTelefono: "<<S2DS4P2[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 2D";
    				cout<<"\nPiso: "<<S2DS4P2[x][y].piso;
    				cout<<"\nSala: "<<S2DS4P2[x][y].sala;
    				cout<<"\nFila: "<<S2DS4P2[x][y].fila;
    				cout<<"\nColumna: "<<S2DS4P2[x][y].columna;
    				cout<<"\nPago: $"<<S2DS4P2[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc6;
    				if((opc6<1)||(opc6>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc6<1)||(opc6>2));
				if(opc6==1)
				{
					Cancelaciones[k] = S2DS4P2[x][y];
					k++;
					S2DS4P2[x][y].TipoDocumento=' ';
					S2DS4P2[x][y].NDocumento=0;
					S2DS4P2[x][y].Nombre=' ';
					S2DS4P2[x][y].Apellido=' ';
					S2DS4P2[x][y].FechaNacimiento=' ';
					S2DS4P2[x][y].Direccion=' ';
					S2DS4P2[x][y].Telefono=' ';
					S2DS4P2[x][y].piso=0;
					S2DS4P2[x][y].sala=0;
					S2DS4P2[x][y].fila=0;
					S2DS4P2[x][y].columna=0;
					S2DS4P2[x][y].ValorPagar=0;
					S2DS4P2[x][y].ocupacion=0;
					S2DS4P2[x][y].TipoR=' ';
				}
				if(S2DS4P2[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S3DS1P3[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S3DS1P3[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S3DS1P3[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S3DS1P3[x][y].Nombre;
    				cout<<"\nApellido: "<<S3DS1P3[x][y].Apellido;
					cout<<"\nFecha de nacimiento: "<<S3DS1P3[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S3DS1P3[x][y].Direccion;
    				cout<<"\nTelefono: "<<S3DS1P3[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 3D";
    				cout<<"\nPiso: "<<S3DS1P3[x][y].piso;
    				cout<<"\nSala: "<<S3DS1P3[x][y].sala;
    				cout<<"\nFila: "<<S3DS1P3[x][y].fila;
    				cout<<"\nColumna: "<<S3DS1P3[x][y].columna;
    				cout<<"\nPago: $"<<S3DS1P3[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc7;
    				if((opc7<1)||(opc7>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc7<1)||(opc7>2));
				if(opc7==1)
				{
					Cancelaciones[k] = S3DS1P3[x][y];
					k++;
					S3DS1P3[x][y].TipoDocumento=' ';
					S3DS1P3[x][y].NDocumento=0;
					S3DS1P3[x][y].Nombre=' ';
					S3DS1P3[x][y].Apellido=' ';
					S3DS1P3[x][y].FechaNacimiento=' ';
					S3DS1P3[x][y].Direccion=' ';
					S3DS1P3[x][y].Telefono=' ';
					S3DS1P3[x][y].piso=0;
					S3DS1P3[x][y].sala=0;
					S3DS1P3[x][y].fila=0;
					S3DS1P3[x][y].columna=0;
					S3DS1P3[x][y].ValorPagar=0;
					S3DS1P3[x][y].ocupacion=0;
					S3DS1P3[x][y].TipoR=' ';
				}
				if(S3DS1P3[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S3DS2P3[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S3DS2P3[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S3DS2P3[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S3DS2P3[x][y].Nombre;
    				cout<<"\nApellido: "<<S3DS2P3[x][y].Apellido;
					cout<<"\nFecha de nacimiento: "<<S3DS2P3[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S3DS2P3[x][y].Direccion;
    				cout<<"\nTelefono: "<<S3DS2P3[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 3D";
    				cout<<"\nPiso: "<<S3DS2P3[x][y].piso;
    				cout<<"\nSala: "<<S3DS2P3[x][y].sala;
    				cout<<"\nFila: "<<S3DS2P3[x][y].fila;
    				cout<<"\nColumna: "<<S3DS2P3[x][y].columna;
    				cout<<"\nPago: $"<<S3DS2P3[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc8;
    				if((opc8<1)||(opc8>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc8<1)||(opc8>2));
				if(opc8==1)
				{
					Cancelaciones[k] = S3DS2P3[x][y];
					k++;
					S3DS2P3[x][y].TipoDocumento=' ';
					S3DS2P3[x][y].NDocumento=0;
					S3DS2P3[x][y].Nombre=' ';
					S3DS2P3[x][y].Apellido=' ';
					S3DS2P3[x][y].FechaNacimiento=' ';
					S3DS2P3[x][y].Direccion=' ';
					S3DS2P3[x][y].Telefono=' ';
					S3DS2P3[x][y].piso=0;
					S3DS2P3[x][y].sala=0;
					S3DS2P3[x][y].fila=0;
					S3DS2P3[x][y].columna=0;
					S3DS2P3[x][y].ValorPagar=0;
					S3DS2P3[x][y].ocupacion=0;
					S3DS2P3[x][y].TipoR=' ';
				}
				if(S3DS2P3[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S3DS3P3[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S3DS3P3[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S3DS3P3[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S3DS3P3[x][y].Nombre;
    				cout<<"\nApellido: "<<S3DS3P3[x][y].Apellido;
					cout<<"\nFecha de nacimiento: "<<S3DS3P3[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S3DS3P3[x][y].Direccion;
    				cout<<"\nTelefono: "<<S3DS3P3[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 3D";
    				cout<<"\nPiso: "<<S3DS3P3[x][y].piso;
    				cout<<"\nSala: "<<S3DS3P3[x][y].sala;
    				cout<<"\nFila: "<<S3DS3P3[x][y].fila;
    				cout<<"\nColumna: "<<S3DS3P3[x][y].columna;
    				cout<<"\nPago: $"<<S3DS3P3[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc9;
    				if((opc9<1)||(opc9>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc9<1)||(opc9>2));
				if(opc9==1)
				{
					Cancelaciones[k] = S3DS3P3[x][y];
					k++;
					S3DS3P3[x][y].TipoDocumento=' ';
					S3DS3P3[x][y].NDocumento=0;
					S3DS3P3[x][y].Nombre=' ';
					S3DS3P3[x][y].Apellido=' ';
					S3DS3P3[x][y].FechaNacimiento=' ';
					S3DS3P3[x][y].Direccion=' ';
					S3DS3P3[x][y].Telefono=' ';
					S3DS3P3[x][y].piso=0;
					S3DS3P3[x][y].sala=0;
					S3DS3P3[x][y].fila=0;
					S3DS3P3[x][y].columna=0;
					S3DS3P3[x][y].ValorPagar=0;
					S3DS3P3[x][y].ocupacion=0;
					S3DS3P3[x][y].TipoR=' ';
				}
				if(S3DS3P3[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			if(id==S3DS4P3[x][y].NDocumento)
			{
				do
				{
					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
					cout<<"\nDatos:\n\n";
					cout<<"Tipo de documento: "<<S3DS4P3[x][y].TipoDocumento;
    				cout<<"\nNumero de documento: "<<S3DS4P3[x][y].NDocumento;
	    			cout<<"\nNombre: "<<S3DS4P3[x][y].Nombre;
    				cout<<"\nApellido: "<<S3DS4P3[x][y].Apellido;
					cout<<"\nFecha de nacimiento: "<<S3DS4P3[x][y].FechaNacimiento;
	    			cout<<"\nDireccion: "<<S3DS4P3[x][y].Direccion;
    				cout<<"\nTelefono: "<<S3DS4P3[x][y].Telefono;
    				cout<<"\n\nReservo Pelicula 3D";
    				cout<<"\nPiso: "<<S3DS4P3[x][y].piso;
    				cout<<"\nSala: "<<S3DS4P3[x][y].sala;
    				cout<<"\nFila: "<<S3DS4P3[x][y].fila;
    				cout<<"\nColumna: "<<S3DS4P3[x][y].columna;
    				cout<<"\nPago: $"<<S3DS4P3[x][y].ValorPagar;
    				cout<<"\n\n";
    				cout<<"Seguro desea cancelar la reserva de este cliente?";
    				cout<<"\n1. Para si";
    				cout<<"\n2. Para no";
    				cout<<"\nOpcion: ";
    				cin>>opc10;
    				if((opc10<1)||(opc10>2))
					{
						fflush(stdin);
						cout<<"\n\tOpcion no valida";
						cout<<"\n\n";
						system("pause");
						system("cls");
						fflush(stdin);	
					}
				}while((opc10<1)||(opc10>2));
				if(opc10==1)
				{
					Cancelaciones[k] = S3DS4P3[x][y];
					k++;
					S3DS4P3[x][y].TipoDocumento=' ';
					S3DS4P3[x][y].NDocumento=0;
					S3DS4P3[x][y].Nombre=' ';
					S3DS4P3[x][y].Apellido=' ';
					S3DS4P3[x][y].FechaNacimiento=' ';
					S3DS4P3[x][y].Direccion=' ';
					S3DS4P3[x][y].Telefono=' ';
					S3DS4P3[x][y].piso=0;
					S3DS4P3[x][y].sala=0;
					S3DS4P3[x][y].fila=0;
					S3DS4P3[x][y].columna=0;
					S3DS4P3[x][y].ValorPagar=0;
					S3DS4P3[x][y].ocupacion=0;
					S3DS4P3[x][y].TipoR=' ';
				}
				if(S3DS4P3[x][y].NDocumento==0)
				{
					
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
				}
    			cout<<endl;
    			opc = 2;
    			system("pause");
				cont++;
			}
			
		}
	}
	for(int x=0;x<30;x++)
	{
		for(int y=0;y<30;y++)
		{
			if(id==S4DS1P4[x][y].NDocumento)
			{	
    				if(S4DS1P4[x][y].ocupacion==1)
    				{
    					do
						{
    						cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
							cout<<"\nDatos:\n\n";
							cout<<"Tipo de documento: "<<S4DS1P4[x][y].TipoDocumento;
    						cout<<"\nNumero de documento: "<<S4DS1P4[x][y].NDocumento;
	    					cout<<"\nNombre: "<<S4DS1P4[x][y].Nombre;
    						cout<<"\nApellido: "<<S4DS1P4[x][y].Apellido;
							cout<<"\nFecha de nacimiento: "<<S4DS1P4[x][y].FechaNacimiento;
	    					cout<<"\nDireccion: "<<S4DS1P4[x][y].Direccion;
	    					fflush(stdin);
    						cout<<"\nTelefono: "<<S4DS1P4[x][y].Telefono;
    						fflush(stdin);
    						cout<<"\n\nReservo Pelicula 4D";
    						cout<<"\nPiso: "<<S4DS1P4[x][y].piso;
    						cout<<"\nSala: "<<S4DS1P4[x][y].sala;
    						cout<<"\nFila: "<<S4DS1P4[x][y].fila;
    						cout<<"\nColumna: "<<S4DS1P4[x][y].columna;
    						cout<<"\nPago: $"<<S4DS1P4[x][y].ValorPagar;
    						cout<<"\n\n";
    						cout<<"Seguro desea cancelar la reserva de este cliente?";
    						cout<<"\n1. Para si";
    						cout<<"\n2. Para no";
    						cout<<"\nOpcion: ";
    						cin>>opc11;
    						if((opc11<1)||(opc11>2))
							{
								fflush(stdin);
								cout<<"\n\tOpcion no valida";
								cout<<"\n\n";
								system("pause");
								system("cls");
								fflush(stdin);	
							}
    					}while((opc11<1)||(opc11>2));
    					if(opc11==1)
						{
							Cancelaciones[k] = S4DS1P4[x][y];
							k++;
							S4DS1P4[x][y].TipoDocumento=' ';
							S4DS1P4[x][y].NDocumento=0;
							S4DS1P4[x][y].Nombre=' ';
							S4DS1P4[x][y].Apellido=' ';
							S4DS1P4[x][y].FechaNacimiento=' ';
							S4DS1P4[x][y].Direccion=' ';
							S4DS1P4[x][y].Telefono=' ';
							S4DS1P4[x][y].piso=0;
							S4DS1P4[x][y].sala=0;
							S4DS1P4[x][y].fila=0;
							S4DS1P4[x][y].columna=0;
							S4DS1P4[x][y].ValorPagar=0;
							S4DS1P4[x][y].ocupacion=0;
							S4DS1P4[x][y].horas=0;
							S4DS1P4[x][y].TipoR=' ';
					
						}
						if(S4DS1P4[x][y].NDocumento==0)
						{
							cout<<"\nLA CANCELACION FUE EXITOSA!\n";
							cont11-=1;
						}
    					cout<<endl;
    					opc = 2;
    					system("pause");
						cont++;
    				}
    				if(S4DS1P4[x][y].ocupacion==2)
    				{
    					do
    					{
    						cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
							cout<<"\nDatos:\n\n";
							cout<<"Tipo de documento: "<<S4DS1P4[x][y].TipoDocumento;
    						cout<<"\nNumero de documento: "<<S4DS1P4[x][y].NDocumento;
	    					cout<<"\nNombre: "<<S4DS1P4[x][y].Nombre;
    						cout<<"\nApellido: "<<S4DS1P4[x][y].Apellido;
							cout<<"\nFecha de nacimiento: "<<S4DS1P4[x][y].FechaNacimiento;
	    					cout<<"\nDireccion: "<<S4DS1P4[x][y].Direccion;
	    					fflush(stdin);
    						cout<<"\nTelefono: "<<S4DS1P4[x][y].Telefono;
    						fflush(stdin);
    						cout<<"\n\nReservo un evento en sala 4D:";
    						cout<<"\nPiso: "<<S4DS1P4[x][y].piso;
    						cout<<"\nSala: "<<S4DS1P4[x][y].sala;
    						cout<<"\nDuracion: "<<S4DS1P4[x][y].horas<<" Horas";
    						cout<<"\nPago: $"<<S4DS1P4[x][y].ValorPagar;
    						cout<<"\n\n";
    						cout<<"Seguro desea cancelar la reserva de este cliente?";
    						cout<<"\n1. Para si";
    						cout<<"\n2. Para no";
    						cout<<"\nOpcion: ";
    						cin>>opc11;
    						if((opc11<1)||(opc11>2))
							{
								fflush(stdin);
								cout<<"\n\tOpcion no valida";
								cout<<"\n\n";
								system("pause");
								system("cls");
								fflush(stdin);	
							}
    					}while((opc11<1)||(opc11>2));
						if(opc11==1)
						{
							Cancelaciones[k] = S4DS1P4[x][y];
							k++;
							S4DS1P4[x][y].TipoDocumento=' ';
							S4DS1P4[x][y].NDocumento=0;
							S4DS1P4[x][y].Nombre=' ';
							S4DS1P4[x][y].Apellido=' ';
							S4DS1P4[x][y].FechaNacimiento=' ';
							S4DS1P4[x][y].Direccion=' ';
							S4DS1P4[x][y].Telefono=' ';
							S4DS1P4[x][y].piso=0;
							S4DS1P4[x][y].sala=0;
							S4DS1P4[x][y].fila=0;
							S4DS1P4[x][y].columna=0;
							S4DS1P4[x][y].ValorPagar=0;
							S4DS1P4[x][y].ocupacion=0;
							S4DS1P4[x][y].horas=0;
							S4DS1P4[x][y].TipoR=' ';
					
						}
						if(S4DS1P4[x][y].NDocumento==0)
						{
							cout<<"\nLA CANCELACION FUE EXITOSA!\n";
							band = 0;
							cont11 = 0;
							for(int x=0;x<30;x++)
    						{
        						for(int y=0;y<30;y++)
      							{
									S4DS1P4[x][y].ocupacion=0;
        						}   
    						}
						}
    					cout<<endl;
    					opc = 2;
    					system("pause");
						cont++;	
					}
					
			}
			if(id==S4DS2P4[x][y].NDocumento)
			{
				if(S4DS2P4[x][y].ocupacion==1)
    			{
    				do
					{
    					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
						cout<<"\nDatos:\n\n";
						cout<<"Tipo de documento: "<<S4DS2P4[x][y].TipoDocumento;
    					cout<<"\nNumero de documento: "<<S4DS2P4[x][y].NDocumento;
	   					cout<<"\nNombre: "<<S4DS2P4[x][y].Nombre;
   						cout<<"\nApellido: "<<S4DS2P4[x][y].Apellido;
						cout<<"\nFecha de nacimiento: "<<S4DS2P4[x][y].FechaNacimiento;
	    				cout<<"\nDireccion: "<<S4DS2P4[x][y].Direccion;
	    				fflush(stdin);
    					cout<<"\nTelefono: "<<S4DS2P4[x][y].Telefono;
    					fflush(stdin);
    					cout<<"\n\nReservo Pelicula 4D";
   						cout<<"\nPiso: "<<S4DS2P4[x][y].piso;
   						cout<<"\nSala: "<<S4DS2P4[x][y].sala;
   						cout<<"\nFila: "<<S4DS2P4[x][y].fila;
    					cout<<"\nColumna: "<<S4DS2P4[x][y].columna;
    					cout<<"\nPago: $"<<S4DS2P4[x][y].ValorPagar;
    					cout<<"\n\n";
    					cout<<"Seguro desea cancelar la reserva de este cliente?";
    					cout<<"\n1. Para si";
   						cout<<"\n2. Para no";
   						cout<<"\nOpcion: ";
   						cin>>opc12;
    					if((opc12<1)||(opc12>2))
						{
							fflush(stdin);
							cout<<"\n\tOpcion no valida";
							cout<<"\n\n";
							system("pause");
							system("cls");
							fflush(stdin);	
						}
    				}while((opc12<1)||(opc12>2));
    				if(opc12==1)
					{
						Cancelaciones[k] = S4DS2P4[x][y];
						k++;
						S4DS2P4[x][y].TipoDocumento=' ';
						S4DS2P4[x][y].NDocumento=0;
						S4DS2P4[x][y].Nombre=' ';
						S4DS2P4[x][y].Apellido=' ';
						S4DS2P4[x][y].FechaNacimiento=' ';
						S4DS2P4[x][y].Direccion=' ';
						S4DS2P4[x][y].Telefono=' ';
						S4DS2P4[x][y].piso=0;
						S4DS2P4[x][y].sala=0;
						S4DS2P4[x][y].fila=0;
						S4DS2P4[x][y].columna=0;
						S4DS2P4[x][y].ValorPagar=0;
						S4DS2P4[x][y].ocupacion=0;
						S4DS2P4[x][y].horas=0;
						S4DS2P4[x][y].TipoR=' ';
				
					}
				if(S4DS2P4[x][y].NDocumento==0)
				{
					cout<<"\nLA CANCELACION FUE EXITOSA!\n";
					cont12-=1;
				}
    			cout<<endl;
   				opc = 2;
    			system("pause");
				cont++;
   				}
    			if(S4DS2P4[x][y].ocupacion==2)
    			{
    				do
    				{
    					cout<<"\n\n\tUSUARIO ENCONTRADO!\n";
						cout<<"\nDatos:\n\n";
						cout<<"Tipo de documento: "<<S4DS2P4[x][y].TipoDocumento;
   						cout<<"\nNumero de documento: "<<S4DS2P4[x][y].NDocumento;
	    				cout<<"\nNombre: "<<S4DS2P4[x][y].Nombre;
    					cout<<"\nApellido: "<<S4DS2P4[x][y].Apellido;
						cout<<"\nFecha de nacimiento: "<<S4DS2P4[x][y].FechaNacimiento;
	    				cout<<"\nDireccion: "<<S4DS2P4[x][y].Direccion;
	    				fflush(stdin);
    					cout<<"\nTelefono: "<<S4DS2P4[x][y].Telefono;
    					fflush(stdin);
   						cout<<"\n\nReservo un evento en sala 4D:";
    					cout<<"\nPiso: "<<S4DS2P4[x][y].piso;
    					cout<<"\nSala: "<<S4DS2P4[x][y].sala;
    					cout<<"\nDuracion: "<<S4DS2P4[x][y].horas<<" Horas";
    					cout<<"\nPago: $"<<S4DS2P4[x][y].ValorPagar;
    					cout<<"\n\n";
    					cout<<"Seguro desea cancelar la reserva de este cliente?";
   						cout<<"\n1. Para si";
    					cout<<"\n2. Para no";
    					cout<<"\nOpcion: ";
    					cin>>opc12;
    					if((opc12<1)||(opc12>2))
						{
							fflush(stdin);
							cout<<"\n\tOpcion no valida";
							cout<<"\n\n";
							system("pause");
							system("cls");
							fflush(stdin);	
						}
    				}while((opc12<1)||(opc12>2));
					if(opc12==1)
					{
						Cancelaciones[k] = S4DS2P4[x][y];
						k++;
						S4DS2P4[x][y].TipoDocumento=' ';
						S4DS2P4[x][y].NDocumento=0;
						S4DS2P4[x][y].Nombre=' ';
						S4DS2P4[x][y].Apellido=' ';
						S4DS2P4[x][y].FechaNacimiento=' ';
						S4DS2P4[x][y].Direccion=' ';
						S4DS2P4[x][y].Telefono=' ';
						S4DS2P4[x][y].piso=0;
						S4DS2P4[x][y].sala=0;
						S4DS2P4[x][y].fila=0;
						S4DS2P4[x][y].columna=0;
						S4DS2P4[x][y].ValorPagar=0;
						S4DS2P4[x][y].ocupacion=0;
						S4DS2P4[x][y].horas=0;
						S4DS2P4[x][y].TipoR=' ';
				
					}
					if(S4DS2P4[x][y].NDocumento==0)
					{
						cout<<"\nLA CANCELACION FUE EXITOSA!\n";
						band2 = 0;
						cont12 = 0;
						for(int x=0;x<30;x++)
    					{
       						for(int y=0;y<30;y++)
     						{
								S4DS2P4[x][y].ocupacion=0;
        					}   
    					}
					}
    				cout<<endl;
    				opc = 2;
    				system("pause");
					cont++;	
				}
			}
		}
		
	}
	
	if(cont==0)
	{
		fflush(stdin);
		cout<<"\n\n\tUSUARIO NO ENCONTRADO\n\n";
	}
	
	cout<<"\nDesea volver a intentarlo?\n";
	cout<<"\n1. Para si";
	cout<<"\n2. Para no\n";
	cout<<"\nOpcion: ";
	cin>>opc;
	
	}while((opc==1));
	
	
}

void ListaReserva()
{
	int c=0;
	
	system("cls");
	fflush(stdin);
	
	cout<<"\n\t\t\t\t\t.:LISTA DE RESERVAS:.\n\n";
	cout<<"\nRESERVA DE PELICULAS:\n\n";
	cout<<"TIPO\t"<<"DOCUMENTO\t"<<"NOMBRE\t"<<"APELLIDO\t"<<"RESERVO\t\t"<<"FILA\t"<<"COLUMNA\t\t"<<"PISO\t"<<"SALA\t"<<"PAG�"<<endl;
	
	for(int x=0;x<4050;x++)
	{
		if(Reservas[x].ocupacion==1)
		{
		   	cout<<Reservas[x].TipoDocumento<<"\t"<<Reservas[x].NDocumento<<"\t"<<Reservas[x].Nombre<<"\t"<<Reservas[x].Apellido<<"\t"<<Reservas[x].TipoR<<"\t"<<Reservas[x].fila<<"\t"<<Reservas[x].columna<<"\t\t"<<Reservas[x].piso<<"\t"<<Reservas[x].sala<<"\t"<<"$"<<Reservas[x].ValorPagar<<endl;
		   	c++;
		}   		
    }
    
    cout<<"\n\nRESERVA DE EVENTO:\n\n";
	cout<<"TIPO\t"<<"DOCUMENTO\t"<<"NOMBRE\t"<<"APELLIDO\t"<<"RESERVO\t\t"<<"HORAS\t"<<"PISO\t"<<"SALA\t"<<"PAG�\t"<<endl;
	
	for(int x=0;x<4050;x++)
	{
		if(Reservas[x].ocupacion==2)
		{
		   	cout<<Reservas[x].TipoDocumento<<"\t"<<Reservas[x].NDocumento<<"\t"<<Reservas[x].Nombre<<"\t"<<Reservas[x].Apellido<<"\t"<<Reservas[x].TipoR<<"\t\t"<<Reservas[x].horas<<"\t"<<Reservas[x].piso<<"\t"<<Reservas[x].sala<<"\t"<<"$"<<Reservas[x].ValorPagar<<endl;
		   	c++;
		}   		
    }
    
    if(c>0)
    {
    	cout<<"\n\nTotal reservas: "<<c;
	}
    if(c==0)
	{
		fflush(stdin);
		system("cls");
		cout<<"\n\n\tNO HAY NINGUN USUARIO REGISTRADO";
	}
	getch();
	
}

void ListaCancelaciones()
{
	int cont=0;
	
	system("cls");
	fflush(stdin);
	
	cout<<"\n\t\t\t\t\t.:LISTA DE CANCELACIONES:.\n\n";
	cout<<"\nCANCELACIONES DE PELICULAS:\n\n";
	cout<<"TIPO\t"<<"DOCUMENTO\t"<<"NOMBRE\t"<<"APELLIDO\t"<<"RESERVO\t\t"<<"FILA\t"<<"COLUMNA\t\t"<<"PISO\t"<<"SALA\t"<<"PAG�\t"<<endl;
	
	for(int x=0;x<4050;x++)
	{
		if(Cancelaciones[x].ocupacion==1)
		{
		   	cout<<Cancelaciones[x].TipoDocumento<<"\t"<<Cancelaciones[x].NDocumento<<"\t"<<Cancelaciones[x].Nombre<<"\t"<<Cancelaciones[x].Apellido<<"\t"<<Cancelaciones[x].TipoR<<"\t"<<Cancelaciones[x].fila<<"\t"<<Cancelaciones[x].columna<<"\t\t"<<Cancelaciones[x].piso<<"\t"<<Cancelaciones[x].sala<<"\t"<<"$"<<Cancelaciones[x].ValorPagar<<endl;
		   	cont++;
		}   		
    }
    
    cout<<"\n\nCANCELACIONES DE EVENTO:\n\n";
	cout<<"TIPO\t"<<"DOCUMENTO\t"<<"NOMBRE\t"<<"APELLIDO\t"<<"RESERVO\t\t"<<"HORAS\t"<<"PISO\t"<<"SALA\t"<<"PAG�\t"<<endl;
	
	for(int x=0;x<4050;x++)
	{
		if(Cancelaciones[x].ocupacion==2)
		{
		   	cout<<Cancelaciones[x].TipoDocumento<<"\t"<<Cancelaciones[x].NDocumento<<"\t"<<Cancelaciones[x].Nombre<<"\t"<<Cancelaciones[x].Apellido<<"\t"<<Cancelaciones[x].TipoR<<"\t\t"<<Cancelaciones[x].horas<<"\t"<<Cancelaciones[x].piso<<"\t"<<Cancelaciones[x].sala<<"\t"<<"$"<<Cancelaciones[x].ValorPagar<<endl;
		   	cont++;
		}   		
    }
    
    if(cont>0)
    {
    	cout<<"\n\nTotal cancelaciones: "<<cont;
	}
    if(cont==0)
	{
		fflush(stdin);
		system("cls");
		cout<<"\n\n\tNO HAY NINGUNA CANCELACION";
	}
	getch();
	
}

void PasarDatos()
{
	siguiente = 0;
	
	for(int i=0;i<4050;i++)
	{
		Reservas[i].ocupacion = 0;
	}
	
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(S2DS1P1[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S2DS1P1[i][j];
				siguiente++;
			}
			if(S2DS2P1[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S2DS2P1[i][j];
				siguiente++;
			}
			if(S2DS1P2[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S2DS1P2[i][j];
				siguiente++;
			}
			if(S2DS2P2[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S2DS2P2[i][j];
				siguiente++;
			}
			if(S2DS3P2[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S2DS3P2[i][j];
				siguiente++;
			}
			if(S2DS4P2[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S2DS4P2[i][j];
				siguiente++;
			}
			if(S3DS1P3[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S3DS1P3[i][j];
				siguiente++;
			}
			if(S3DS2P3[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S3DS2P3[i][j];
				siguiente++;
			}
			if(S3DS3P3[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S3DS3P3[i][j];
				siguiente++;
			}
			if(S3DS4P3[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S3DS4P3[i][j];
				siguiente++;
			}
		}
	}
	
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
		{
			if(S4DS1P4[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S4DS1P4[i][j];
				siguiente++;
			}
			if(S4DS2P4[i][j].ocupacion == 1)
			{
				Reservas[siguiente] = S4DS2P4[i][j];
				siguiente++;
			}
			if(S4DS1P4[i][j].ocupacion == 2)
			{
				Reservas[siguiente] = S4DS1P4[i][j];
				siguiente++;
			}
			if(S4DS2P4[i][j].ocupacion == 2)
			{
				Reservas[siguiente] = S4DS2P4[i][j];
				siguiente++;
			}
		}
	}
}

void OrdenarCedulaR()
{
	int n=siguiente;
	
	for(int i = 0 ; i <= n-2 ; i++)
	{
		for(int j = i+1 ; j <= n-1 ; j++)
		{
			if(Reservas[i].NDocumento > Reservas[j].NDocumento)
			{
				aux = Reservas[i];
				Reservas[i] = Reservas[j];
				Reservas[j] = aux;
			}
		}
	}
}

void OrdenarCedulaC()
{
	int n=k;
	
	for(int  i = 0 ; i <= n-2 ; i++)
	{
		for(int j = i+1 ; j <= n-1 ; j++)
		{
			if(Cancelaciones[i].NDocumento > Cancelaciones[j].NDocumento)
			{
				aux = Cancelaciones[i];
				Cancelaciones[i] = Cancelaciones[j];
				Cancelaciones[j] = aux;
			}
		}
	}
}

void OrdenarApellidoR()
{
	int n=siguiente;
	
	for(int i = 0 ; i <= n-2 ; i++)
	{
		for(int j = i+1 ; j <= n-1 ; j++)
		{
			if(Reservas[i].Apellido == Reservas[j].Apellido)
			{
				if(Reservas[i].Nombre > Reservas[j].Nombre)
				{
					aux = Reservas[i];
					Reservas[i] = Reservas[j];
					Reservas[j] = aux;
				}
			}
			else
			{
				if(Reservas[i].Apellido > Reservas[j].Apellido)
				{
					aux = Reservas[i];
					Reservas[i] = Reservas[j];
					Reservas[j] = aux;
				}
			}
		}
	}
}

void OrdenarApellidoC()
{
	int n=k;
	
	for(int i = 0 ; i <= n-2 ; i++)
	{
		for(int j = i+1 ; j <= n-1 ; j++)
		{
			if(Cancelaciones[i].Apellido == Cancelaciones[j].Apellido)
			{
				if(Cancelaciones[i].Nombre > Cancelaciones[j].Nombre)
				{
					aux = Cancelaciones[i];
					Cancelaciones[i] = Cancelaciones[j];
					Cancelaciones[j] = aux;
				}
			}
			else
			{
				if(Cancelaciones[i].Apellido > Cancelaciones[j].Apellido)
				{
					aux = Cancelaciones[i];
					Cancelaciones[i] = Cancelaciones[j];
					Cancelaciones[j] = aux;
				}
			}
		}
	}
}

void BarraProgreso()
{
	int segundos=5;
	
	for(int i=0; i<=7; i++)
		cout << "\n";
		
	cout << "\t\t\t CARGANDO LOS DATOS...\n";
	
	for(int i=0; i<=79; i++)
		cout << "_";
	
	for(int i=0; i<=79; i++)
	{
		cout<<char(219);
		Sleep(segundos*1000/500);
	}
	cout<<"\n COMPLETADO!";
}

void GuardarDatos()
{
	BarraProgreso();
	
	entrada.open("ClientesPolombia.txt",ios::out|ios::trunc);
	
	if(entrada.fail())
	{
		system("cls");
		cout<<"\n\tERROR AL ABRIR EL ARCHIVO"<<endl;
		getch();
	}
	else
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<15;j++)
			{
				if(S2DS1P1[i][j].ocupacion == 1)
				{
					entrada<<S2DS1P1[i][j].TipoDocumento<<" "<<S2DS1P1[i][j].NDocumento<<" "<<S2DS1P1[i][j].Nombre<<" "<<S2DS1P1[i][j].Apellido<<" "<<S2DS1P1[i][j].FechaNacimiento<<" "<<S2DS1P1[i][j].Direccion<<" "<<S2DS1P1[i][j].Telefono<<" "<<S2DS1P1[i][j].ValorPagar<<" "<<S2DS1P1[i][j].ocupacion<<" "<<S2DS1P1[i][j].fila<<" "<<S2DS1P1[i][j].columna<<" "<<S2DS1P1[i][j].piso<<" "<<S2DS1P1[i][j].sala<<" "<<S2DS1P1[i][j].horas<<" "<<S2DS1P1[i][j].TipoR<<endl;
				}
				if(S2DS2P1[i][j].ocupacion == 1)
				{
					entrada<<S2DS2P1[i][j].TipoDocumento<<" "<<S2DS2P1[i][j].NDocumento<<" "<<S2DS2P1[i][j].Nombre<<" "<<S2DS2P1[i][j].Apellido<<" "<<S2DS2P1[i][j].FechaNacimiento<<" "<<S2DS2P1[i][j].Direccion<<" "<<S2DS2P1[i][j].Telefono<<" "<<S2DS2P1[i][j].ValorPagar<<" "<<S2DS2P1[i][j].ocupacion<<" "<<S2DS2P1[i][j].fila<<" "<<S2DS2P1[i][j].columna<<" "<<S2DS2P1[i][j].piso<<" "<<S2DS2P1[i][j].sala<<" "<<S2DS2P1[i][j].horas<<" "<<S2DS2P1[i][j].TipoR<<endl;
				}
				if(S2DS1P2[i][j].ocupacion == 1)
				{
					entrada<<S2DS1P2[i][j].TipoDocumento<<" "<<S2DS1P2[i][j].NDocumento<<" "<<S2DS1P2[i][j].Nombre<<" "<<S2DS1P2[i][j].Apellido<<" "<<S2DS1P2[i][j].FechaNacimiento<<" "<<S2DS1P2[i][j].Direccion<<" "<<S2DS1P2[i][j].Telefono<<" "<<S2DS1P2[i][j].ValorPagar<<" "<<S2DS1P2[i][j].ocupacion<<" "<<S2DS1P2[i][j].fila<<" "<<S2DS1P2[i][j].columna<<" "<<S2DS1P2[i][j].piso<<" "<<S2DS1P2[i][j].sala<<" "<<S2DS1P2[i][j].horas<<" "<<S2DS1P2[i][j].TipoR<<endl;
				}
				if(S2DS2P2[i][j].ocupacion == 1)
				{
					entrada<<S2DS2P2[i][j].TipoDocumento<<" "<<S2DS2P2[i][j].NDocumento<<" "<<S2DS2P2[i][j].Nombre<<" "<<S2DS2P2[i][j].Apellido<<" "<<S2DS2P2[i][j].FechaNacimiento<<" "<<S2DS2P2[i][j].Direccion<<" "<<S2DS2P2[i][j].Telefono<<" "<<S2DS2P2[i][j].ValorPagar<<" "<<S2DS2P2[i][j].ocupacion<<" "<<S2DS2P2[i][j].fila<<" "<<S2DS2P2[i][j].columna<<" "<<S2DS2P2[i][j].piso<<" "<<S2DS2P2[i][j].sala<<" "<<S2DS2P2[i][j].horas<<" "<<S2DS2P2[i][j].TipoR<<endl;
				}
				if(S2DS3P2[i][j].ocupacion == 1)
				{
					entrada<<S2DS3P2[i][j].TipoDocumento<<" "<<S2DS3P2[i][j].NDocumento<<" "<<S2DS3P2[i][j].Nombre<<" "<<S2DS3P2[i][j].Apellido<<" "<<S2DS3P2[i][j].FechaNacimiento<<" "<<S2DS3P2[i][j].Direccion<<" "<<S2DS3P2[i][j].Telefono<<" "<<S2DS3P2[i][j].ValorPagar<<" "<<S2DS3P2[i][j].ocupacion<<" "<<S2DS3P2[i][j].fila<<" "<<S2DS3P2[i][j].columna<<" "<<S2DS3P2[i][j].piso<<" "<<S2DS3P2[i][j].sala<<" "<<S2DS3P2[i][j].horas<<" "<<S2DS3P2[i][j].TipoR<<endl;
				}
				if(S2DS4P2[i][j].ocupacion == 1)
				{
					entrada<<S2DS4P2[i][j].TipoDocumento<<" "<<S2DS4P2[i][j].NDocumento<<" "<<S2DS4P2[i][j].Nombre<<" "<<S2DS4P2[i][j].Apellido<<" "<<S2DS4P2[i][j].FechaNacimiento<<" "<<S2DS4P2[i][j].Direccion<<" "<<S2DS4P2[i][j].Telefono<<" "<<S2DS4P2[i][j].ValorPagar<<" "<<S2DS4P2[i][j].ocupacion<<" "<<S2DS4P2[i][j].fila<<" "<<S2DS4P2[i][j].columna<<" "<<S2DS4P2[i][j].piso<<" "<<S2DS4P2[i][j].sala<<" "<<S2DS4P2[i][j].horas<<" "<<S2DS4P2[i][j].TipoR<<endl;
				}
				if(S3DS1P3[i][j].ocupacion == 1)
				{
					entrada<<S3DS1P3[i][j].TipoDocumento<<" "<<S3DS1P3[i][j].NDocumento<<" "<<S3DS1P3[i][j].Nombre<<" "<<S3DS1P3[i][j].Apellido<<" "<<S3DS1P3[i][j].FechaNacimiento<<" "<<S3DS1P3[i][j].Direccion<<" "<<S3DS1P3[i][j].Telefono<<" "<<S3DS1P3[i][j].ValorPagar<<" "<<S3DS1P3[i][j].ocupacion<<" "<<S3DS1P3[i][j].fila<<" "<<S3DS1P3[i][j].columna<<" "<<S3DS1P3[i][j].piso<<" "<<S3DS1P3[i][j].sala<<" "<<S3DS1P3[i][j].horas<<" "<<S3DS1P3[i][j].TipoR<<endl;
				}
				if(S3DS2P3[i][j].ocupacion == 1)
				{
					entrada<<S3DS2P3[i][j].TipoDocumento<<" "<<S3DS2P3[i][j].NDocumento<<" "<<S3DS2P3[i][j].Nombre<<" "<<S3DS2P3[i][j].Apellido<<" "<<S3DS2P3[i][j].FechaNacimiento<<" "<<S3DS2P3[i][j].Direccion<<" "<<S3DS2P3[i][j].Telefono<<" "<<S3DS2P3[i][j].ValorPagar<<" "<<S3DS2P3[i][j].ocupacion<<" "<<S3DS2P3[i][j].fila<<" "<<S3DS2P3[i][j].columna<<" "<<S3DS2P3[i][j].piso<<" "<<S3DS2P3[i][j].sala<<" "<<S3DS2P3[i][j].horas<<" "<<S3DS2P3[i][j].TipoR<<endl;
				}
				if(S3DS3P3[i][j].ocupacion == 1)
				{
					entrada<<S3DS3P3[i][j].TipoDocumento<<" "<<S3DS3P3[i][j].NDocumento<<" "<<S3DS3P3[i][j].Nombre<<" "<<S3DS3P3[i][j].Apellido<<" "<<S3DS3P3[i][j].FechaNacimiento<<" "<<S3DS3P3[i][j].Direccion<<" "<<S3DS3P3[i][j].Telefono<<" "<<S3DS3P3[i][j].ValorPagar<<" "<<S3DS3P3[i][j].ocupacion<<" "<<S3DS3P3[i][j].fila<<" "<<S3DS3P3[i][j].columna<<" "<<S3DS3P3[i][j].piso<<" "<<S3DS3P3[i][j].sala<<" "<<S3DS3P3[i][j].horas<<" "<<S3DS3P3[i][j].TipoR<<endl;
				}
				if(S3DS4P3[i][j].ocupacion == 1)
				{
					entrada<<S3DS4P3[i][j].TipoDocumento<<" "<<S3DS4P3[i][j].NDocumento<<" "<<S3DS4P3[i][j].Nombre<<" "<<S3DS4P3[i][j].Apellido<<" "<<S3DS4P3[i][j].FechaNacimiento<<" "<<S3DS4P3[i][j].Direccion<<" "<<S3DS4P3[i][j].Telefono<<" "<<S3DS4P3[i][j].ValorPagar<<" "<<S3DS4P3[i][j].ocupacion<<" "<<S3DS4P3[i][j].fila<<" "<<S3DS4P3[i][j].columna<<" "<<S3DS4P3[i][j].piso<<" "<<S3DS4P3[i][j].sala<<" "<<S3DS4P3[i][j].horas<<" "<<S3DS4P3[i][j].TipoR<<endl;
				}
			}
		}
		for(int i=0;i<30;i++)
		{
			for(int j=0;j<30;j++)
			{
				if(S4DS1P4[i][j].ocupacion == 1)
				{
					entrada<<S4DS1P4[i][j].TipoDocumento<<" "<<S4DS1P4[i][j].NDocumento<<" "<<S4DS1P4[i][j].Nombre<<" "<<S4DS1P4[i][j].Apellido<<" "<<S4DS1P4[i][j].FechaNacimiento<<" "<<S4DS1P4[i][j].Direccion<<" "<<S4DS1P4[i][j].Telefono<<" "<<S4DS1P4[i][j].ValorPagar<<" "<<S4DS1P4[i][j].ocupacion<<" "<<S4DS1P4[i][j].fila<<" "<<S4DS1P4[i][j].columna<<" "<<S4DS1P4[i][j].piso<<" "<<S4DS1P4[i][j].sala<<" "<<S4DS1P4[i][j].horas<<" "<<S4DS1P4[i][j].TipoR<<endl;
				}
				if(S4DS2P4[i][j].ocupacion == 1)
				{
					entrada<<S4DS2P4[i][j].TipoDocumento<<" "<<S4DS2P4[i][j].NDocumento<<" "<<S4DS2P4[i][j].Nombre<<" "<<S4DS2P4[i][j].Apellido<<" "<<S4DS2P4[i][j].FechaNacimiento<<" "<<S4DS2P4[i][j].Direccion<<" "<<S4DS2P4[i][j].Telefono<<" "<<S4DS2P4[i][j].ValorPagar<<" "<<S4DS2P4[i][j].ocupacion<<" "<<S4DS2P4[i][j].fila<<" "<<S4DS2P4[i][j].columna<<" "<<S4DS2P4[i][j].piso<<" "<<S4DS2P4[i][j].sala<<" "<<S4DS2P4[i][j].horas<<" "<<S4DS2P4[i][j].TipoR<<endl;
				}
				if(S4DS1P4[i][j].ocupacion == 2)
				{
					entrada<<S4DS1P4[i][j].TipoDocumento<<" "<<S4DS1P4[i][j].NDocumento<<" "<<S4DS1P4[i][j].Nombre<<" "<<S4DS1P4[i][j].Apellido<<" "<<S4DS1P4[i][j].FechaNacimiento<<" "<<S4DS1P4[i][j].Direccion<<" "<<S4DS1P4[i][j].Telefono<<" "<<S4DS1P4[i][j].ValorPagar<<" "<<S4DS1P4[i][j].ocupacion<<" "<<S4DS1P4[i][j].fila<<" "<<S4DS1P4[i][j].columna<<" "<<S4DS1P4[i][j].piso<<" "<<S4DS1P4[i][j].sala<<" "<<S4DS1P4[i][j].horas<<" "<<S4DS1P4[i][j].TipoR<<endl;
				}
				if(S4DS2P4[i][j].ocupacion == 2)
				{
					entrada<<S4DS2P4[i][j].TipoDocumento<<" "<<S4DS2P4[i][j].NDocumento<<" "<<S4DS2P4[i][j].Nombre<<" "<<S4DS2P4[i][j].Apellido<<" "<<S4DS2P4[i][j].FechaNacimiento<<" "<<S4DS2P4[i][j].Direccion<<" "<<S4DS2P4[i][j].Telefono<<" "<<S4DS2P4[i][j].ValorPagar<<" "<<S4DS2P4[i][j].ocupacion<<" "<<S4DS2P4[i][j].fila<<" "<<S4DS2P4[i][j].columna<<" "<<S4DS2P4[i][j].piso<<" "<<S4DS2P4[i][j].sala<<" "<<S4DS2P4[i][j].horas<<" "<<S4DS2P4[i][j].TipoR<<endl;
				}
			}
		}
	}
	
	entrada.close();
}

void GuardarCancelaciones()
{
	entrada.open("CancelacionesPolombia.txt",ios::out|ios::trunc);
	
	if(entrada.fail())
	{
		system("cls");
		cout<<"\n\tERROR AL ABRIR EL ARCHIVO"<<endl;
		getch();
	}
	else
	{
		for(int i=0;i<4050;i++)
		{
			if(Cancelaciones[i].ocupacion==1)
			{
				entrada<<Cancelaciones[i].TipoDocumento<<" "<<Cancelaciones[i].NDocumento<<" "<<Cancelaciones[i].Nombre<<" "<<Cancelaciones[i].Apellido<<" "<<Cancelaciones[i].FechaNacimiento<<" "<<Cancelaciones[i].Direccion<<" "<<Cancelaciones[i].Telefono<<" "<<Cancelaciones[i].ValorPagar<<" "<<Cancelaciones[i].ocupacion<<" "<<Cancelaciones[i].fila<<" "<<Cancelaciones[i].columna<<" "<<Cancelaciones[i].piso<<" "<<Cancelaciones[i].sala<<" "<<Cancelaciones[i].horas<<" "<<Cancelaciones[i].TipoR<<endl;
			}
			if(Cancelaciones[i].ocupacion==2)
			{
				entrada<<Cancelaciones[i].TipoDocumento<<" "<<Cancelaciones[i].NDocumento<<" "<<Cancelaciones[i].Nombre<<" "<<Cancelaciones[i].Apellido<<" "<<Cancelaciones[i].FechaNacimiento<<" "<<Cancelaciones[i].Direccion<<" "<<Cancelaciones[i].Telefono<<" "<<Cancelaciones[i].ValorPagar<<" "<<Cancelaciones[i].ocupacion<<" "<<Cancelaciones[i].fila<<" "<<Cancelaciones[i].columna<<" "<<Cancelaciones[i].piso<<" "<<Cancelaciones[i].sala<<" "<<Cancelaciones[i].horas<<" "<<Cancelaciones[i].TipoR<<endl;
			}
		}
	}
	entrada.close();
}

void GuardarTools()
{
	entrada.open("ToolsPolombia.txt",ios::out|ios::trunc);
	
	if(entrada.fail())
	{
		system("cls");
		cout<<"\n\tERROR AL ABRIR EL ARCHIVO"<<endl;
		getch();
	}
	else
	{
		entrada<<siguiente<<" "<<k<<" "<<band<<" "<<band2<<" "<<cont<<" "<<cont2<<" "<<cont3<<" "<<cont4<<" "<<cont5<<" "<<cont6<<" "<<cont7<<" "<<cont8<<" "<<cont9<<" "<<cont10<<" "<<cont11<<" "<<cont12<<endl;
	}
	entrada.close();
}

void RecuperarTools()
{
	salida.open("ToolsPolombia.txt",ios::in);
	
	if(salida.fail())
	{
		system("cls");
		cout<<"\n\tERROR AL ABRIR EL ARCHIVO"<<endl;
		getch();
	}
	else
	{
		salida>>siguiente>>k>>band>>band2>>cont>>cont2>>cont3>>cont4>>cont5>>cont6>>cont7>>cont8>>cont9>>cont10>>cont11>>cont12;
	}
	salida.close();
}

void RecuperarDatos()
{
	BarraProgreso();
	
	salida.open("ClientesPolombia.txt",ios::in);
	
	if(salida.fail())
	{
		system("cls");
		cout<<"\n\tERROR AL ABRIR EL ARCHIVO"<<endl;
		getch();
	}
	else
	{
		while(salida>>tdoc>>ndoc>>name>>apel>>naci>>dir>>tel>>pago>>ocup>>fil>>col>>pis>>sal>>hora>>tipor)
		{
			if((pis==1)&&(sal==1))
			{
				S2DS1P1[fil][col].TipoDocumento=tdoc;
				S2DS1P1[fil][col].NDocumento=ndoc;
				S2DS1P1[fil][col].Nombre=name;
				S2DS1P1[fil][col].Apellido=apel;
				S2DS1P1[fil][col].FechaNacimiento=naci;
				S2DS1P1[fil][col].Direccion=dir;
				S2DS1P1[fil][col].Telefono=tel;
				S2DS1P1[fil][col].ValorPagar=pago;
				S2DS1P1[fil][col].ocupacion=ocup;
				S2DS1P1[fil][col].fila=fil;
				S2DS1P1[fil][col].columna=col;
				S2DS1P1[fil][col].piso=pis;
				S2DS1P1[fil][col].sala=sal;
				S2DS1P1[fil][col].horas=hora;
				S2DS1P1[fil][col].TipoR=tipor;
			}
			if((pis==1)&&(sal==2))
			{
				S2DS2P1[fil][col].TipoDocumento=tdoc;
				S2DS2P1[fil][col].NDocumento=ndoc;
				S2DS2P1[fil][col].Nombre=name;
				S2DS2P1[fil][col].Apellido=apel;
				S2DS2P1[fil][col].FechaNacimiento=naci;
				S2DS2P1[fil][col].Direccion=dir;
				S2DS2P1[fil][col].Telefono=tel;
				S2DS2P1[fil][col].ValorPagar=pago;
				S2DS2P1[fil][col].ocupacion=ocup;
				S2DS2P1[fil][col].fila=fil;
				S2DS2P1[fil][col].columna=col;
				S2DS2P1[fil][col].piso=pis;
				S2DS2P1[fil][col].sala=sal;
				S2DS2P1[fil][col].horas=hora;
				S2DS2P1[fil][col].TipoR=tipor;
			}
		
			if((pis==2)&&(sal==1))
			{
				S2DS1P2[fil][col].TipoDocumento=tdoc;
				S2DS1P2[fil][col].NDocumento=ndoc;
				S2DS1P2[fil][col].Nombre=name;
				S2DS1P2[fil][col].Apellido=apel;
				S2DS1P2[fil][col].FechaNacimiento=naci;
				S2DS1P2[fil][col].Direccion=dir;
				S2DS1P2[fil][col].Telefono=tel;
				S2DS1P2[fil][col].ValorPagar=pago;
				S2DS1P2[fil][col].ocupacion=ocup;
				S2DS1P2[fil][col].fila=fil;
				S2DS1P2[fil][col].columna=col;
				S2DS1P2[fil][col].piso=pis;
				S2DS1P2[fil][col].sala=sal;
				S2DS1P2[fil][col].horas=hora;
				S2DS1P2[fil][col].TipoR=tipor;
			}
			if((pis==2)&&(sal==2))
			{
				S2DS2P2[fil][col].TipoDocumento=tdoc;
				S2DS2P2[fil][col].NDocumento=ndoc;
				S2DS2P2[fil][col].Nombre=name;
				S2DS2P2[fil][col].Apellido=apel;
				S2DS2P2[fil][col].FechaNacimiento=naci;
				S2DS2P2[fil][col].Direccion=dir;
				S2DS2P2[fil][col].Telefono=tel;
				S2DS2P2[fil][col].ValorPagar=pago;
				S2DS2P2[fil][col].ocupacion=ocup;
				S2DS2P2[fil][col].fila=fil;
				S2DS2P2[fil][col].columna=col;
				S2DS2P2[fil][col].piso=pis;
				S2DS2P2[fil][col].sala=sal;
				S2DS2P2[fil][col].horas=hora;
				S2DS2P2[fil][col].TipoR=tipor;
			}
			if((pis==2)&&(sal==3))
			{
				S2DS3P2[fil][col].TipoDocumento=tdoc;
				S2DS3P2[fil][col].NDocumento=ndoc;
				S2DS3P2[fil][col].Nombre=name;
				S2DS3P2[fil][col].Apellido=apel;
				S2DS3P2[fil][col].FechaNacimiento=naci;
				S2DS3P2[fil][col].Direccion=dir;
				S2DS3P2[fil][col].Telefono=tel;
				S2DS3P2[fil][col].ValorPagar=pago;
				S2DS3P2[fil][col].ocupacion=ocup;
				S2DS3P2[fil][col].fila=fil;
				S2DS3P2[fil][col].columna=col;
				S2DS3P2[fil][col].piso=pis;
				S2DS3P2[fil][col].sala=sal;
				S2DS3P2[fil][col].horas=hora;
				S2DS3P2[fil][col].TipoR=tipor;
			}
			if((pis==2)&&(sal==4))
			{
				S2DS4P2[fil][col].TipoDocumento=tdoc;
				S2DS4P2[fil][col].NDocumento=ndoc;
				S2DS4P2[fil][col].Nombre=name;
				S2DS4P2[fil][col].Apellido=apel;
				S2DS4P2[fil][col].FechaNacimiento=naci;
				S2DS4P2[fil][col].Direccion=dir;
				S2DS4P2[fil][col].Telefono=tel;
				S2DS4P2[fil][col].ValorPagar=pago;
				S2DS4P2[fil][col].ocupacion=ocup;
				S2DS4P2[fil][col].fila=fil;
				S2DS4P2[fil][col].columna=col;
				S2DS4P2[fil][col].piso=pis;
				S2DS4P2[fil][col].sala=sal;
				S2DS4P2[fil][col].horas=hora;
				S2DS4P2[fil][col].TipoR=tipor;
			}
			if((pis==3)&&(sal==1))
			{
				S3DS1P3[fil][col].TipoDocumento=tdoc;
				S3DS1P3[fil][col].NDocumento=ndoc;
				S3DS1P3[fil][col].Nombre=name;
				S3DS1P3[fil][col].Apellido=apel;
				S3DS1P3[fil][col].FechaNacimiento=naci;
				S3DS1P3[fil][col].Direccion=dir;
				S3DS1P3[fil][col].Telefono=tel;
				S3DS1P3[fil][col].ValorPagar=pago;
				S3DS1P3[fil][col].ocupacion=ocup;
				S3DS1P3[fil][col].fila=fil;
				S3DS1P3[fil][col].columna=col;
				S3DS1P3[fil][col].piso=pis;
				S3DS1P3[fil][col].sala=sal;
				S3DS1P3[fil][col].horas=hora;
				S3DS1P3[fil][col].TipoR=tipor;
			}
			if((pis==3)&&(sal==2))
			{
				S3DS2P3[fil][col].TipoDocumento=tdoc;
				S3DS2P3[fil][col].NDocumento=ndoc;
				S3DS2P3[fil][col].Nombre=name;
				S3DS2P3[fil][col].Apellido=apel;
				S3DS2P3[fil][col].FechaNacimiento=naci;
				S3DS2P3[fil][col].Direccion=dir;
				S3DS2P3[fil][col].Telefono=tel;
				S3DS2P3[fil][col].ValorPagar=pago;
				S3DS2P3[fil][col].ocupacion=ocup;
				S3DS2P3[fil][col].fila=fil;
				S3DS2P3[fil][col].columna=col;
				S3DS2P3[fil][col].piso=pis;
				S3DS2P3[fil][col].sala=sal;
				S3DS2P3[fil][col].horas=hora;
				S3DS2P3[fil][col].TipoR=tipor;
			}
			if((pis==3)&&(sal==3))
			{
				S3DS3P3[fil][col].TipoDocumento=tdoc;
				S3DS3P3[fil][col].NDocumento=ndoc;
				S3DS3P3[fil][col].Nombre=name;
				S3DS3P3[fil][col].Apellido=apel;
				S3DS3P3[fil][col].FechaNacimiento=naci;
				S3DS3P3[fil][col].Direccion=dir;
				S3DS3P3[fil][col].Telefono=tel;
				S3DS3P3[fil][col].ValorPagar=pago;
				S3DS3P3[fil][col].ocupacion=ocup;
				S3DS3P3[fil][col].fila=fil;
				S3DS3P3[fil][col].columna=col;
				S3DS3P3[fil][col].piso=pis;
				S3DS3P3[fil][col].sala=sal;
				S3DS3P3[fil][col].horas=hora;
				S3DS3P3[fil][col].TipoR=tipor;
			}
			if((pis==3)&&(sal==4))
			{
				S3DS4P3[fil][col].TipoDocumento=tdoc;
				S3DS4P3[fil][col].NDocumento=ndoc;
				S3DS4P3[fil][col].Nombre=name;
				S3DS4P3[fil][col].Apellido=apel;
				S3DS4P3[fil][col].FechaNacimiento=naci;
				S3DS4P3[fil][col].Direccion=dir;
				S3DS4P3[fil][col].Telefono=tel;
				S3DS4P3[fil][col].ValorPagar=pago;
				S3DS4P3[fil][col].ocupacion=ocup;
				S3DS4P3[fil][col].fila=fil;
				S3DS4P3[fil][col].columna=col;
				S3DS4P3[fil][col].piso=pis;
				S3DS4P3[fil][col].sala=sal;
				S3DS4P3[fil][col].horas=hora;
				S3DS4P3[fil][col].TipoR=tipor;
			}
			if((pis==4)&&(sal==1))
			{
				S4DS1P4[fil][col].TipoDocumento=tdoc;
				S4DS1P4[fil][col].NDocumento=ndoc;
				S4DS1P4[fil][col].Nombre=name;
				S4DS1P4[fil][col].Apellido=apel;
				S4DS1P4[fil][col].FechaNacimiento=naci;
				S4DS1P4[fil][col].Direccion=dir;
				S4DS1P4[fil][col].Telefono=tel;
				S4DS1P4[fil][col].ValorPagar=pago;
				S4DS1P4[fil][col].ocupacion=ocup;
				S4DS1P4[fil][col].fila=fil;
				S4DS1P4[fil][col].columna=col;
				S4DS1P4[fil][col].piso=pis;
				S4DS1P4[fil][col].sala=sal;
				S4DS1P4[fil][col].horas=hora;
				S4DS1P4[fil][col].TipoR=tipor;
			}
			if((pis==4)&&(sal==2))
			{
				S4DS2P4[fil][col].TipoDocumento=tdoc;
				S4DS2P4[fil][col].NDocumento=ndoc;
				S4DS2P4[fil][col].Nombre=name;
				S4DS2P4[fil][col].Apellido=apel;
				S4DS2P4[fil][col].FechaNacimiento=naci;
				S4DS2P4[fil][col].Direccion=dir;
				S4DS2P4[fil][col].Telefono=tel;
				S4DS2P4[fil][col].ValorPagar=pago;
				S4DS2P4[fil][col].ocupacion=ocup;
				S4DS2P4[fil][col].fila=fil;
				S4DS2P4[fil][col].columna=col;
				S4DS2P4[fil][col].piso=pis;
				S4DS2P4[fil][col].sala=sal;
				S4DS2P4[fil][col].horas=hora;
				S4DS2P4[fil][col].TipoR=tipor;
			}
		}
	}
	salida.close();
}

void RecuperarCancelaciones()
{
	int i=0;
	
	salida.open("CancelacionesPolombia.txt",ios::in);
	
	if(salida.fail())
	{
		system("cls");
		cout<<"\n\tERROR AL ABRIR EL ARCHIVO"<<endl;
		getch();
	}
	else
	{
		while(salida>>tdoc>>ndoc>>name>>apel>>naci>>dir>>tel>>pago>>ocup>>fil>>col>>pis>>sal>>hora>>tipor)
		{
			if(i<4050)
			{
				Cancelaciones[i].TipoDocumento=tdoc;
				Cancelaciones[i].NDocumento=ndoc;
				Cancelaciones[i].Nombre=name;
				Cancelaciones[i].Apellido=apel;
				Cancelaciones[i].FechaNacimiento=naci;
				Cancelaciones[i].Direccion=dir;
				Cancelaciones[i].Telefono=tel;
				Cancelaciones[i].ValorPagar=pago;
				Cancelaciones[i].ocupacion=ocup;
				Cancelaciones[i].fila=fil;
				Cancelaciones[i].columna=col;
				Cancelaciones[i].piso=pis;
				Cancelaciones[i].sala=sal;
				Cancelaciones[i].horas=hora;
				Cancelaciones[i].TipoR=tipor;
				i++;
			}
		}
	}
	salida.close();
}

/*
BY BRAYAN ESTIBEN RODALLEGA SAAVEDRA
Twitter: https://twitter.com/brayan1a1
YouTube: https://www.youtube.com/c/brayan1a1
GitHub: https://github.com/brayanrodallega
LinkedIn: https://www.linkedin.com/in/brayanrodallega
*/
