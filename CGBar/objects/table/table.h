#ifndef _TABLE_H_
#define _TABLE_H_

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da t�bua da mesa;
	float ALTURA: Altura dos p�s da mesa; 
	float RAIO: Raio dos p�s da mesa;	
	int NVERTICES: N�mero de v�rtices usado para desenhar os p�s da mesa (cilindro).
	int NCAMADAS: N�mero de camadas usado para as primitivas de cilindro e plano;	
*/
void drawTable(float largura_tabua, float comprimento_tabua, float altura_tabua, float altura_pes, float raio_pes, int n_vertices_pes, int n_camadas) ;

/*	Desenha mesa centrada na origem com liga��es entre os p�s:
	float LARGURA_TABUA, COMPRIMENTO_TABUA, ALTURA_TABUA: Comprimento, largura e altura da t�bua da mesa;
	float ALTURA_PES: Altura dos p�s da mesa; 
	float RAIO_PES: Raio dos p�s da mesa;	
	int N_VERTICES_PES: N�mero de v�rtices usado para desenhar os p�s da mesa (cilindro).
	int N_CAMADAS: N�mero de camadas usado para as primitivas de cilindro e plano;	
*/
void drawTable2(float largura_tabua, float comprimento_tabua, float altura_tabua, float altura_pes, float raio_pes, int n_vertices_pes, int n_camadas) ;


/*	Desenha mesa redonda, com um s� p�, centrada na origem:
	float RAIO_TABUA, ALTURA_TABUA: Raio e altura do cilindro que representa a t�bua da mesa;
	float RAIO_PE, ALTURA_PE: Raio e altura do p� da mesa (cilindro); 		
	float RAIO_BASE, ALTURA_BASE: Raio e altura do cilindro que representa a base da mesa;
	int N_VERTICES: N�mero de v�rtices usado para desenhar o cilindros.
	int N_CAMADAS: N�mero de camadas usadas para desenhar o cilindro ;	
*/
void drawTableCircular(float raio_tabua, float altura_tabua, float raio_pe, float altura_pe, float raio_base, float altura_base, int n_vertices, int n_camadas) ;


#endif