DESHAIES Christopher

Doit contenir :
- ce que vous n'avez pas fait (et pourquoi). Précisez explicitement "tout à été fait et fonctionne parfaitement" si c'est le cas.
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc). 

Question 7.
	Modification effectué sur les fonctions :
		sur void GLApplication::draw():
			- modification du glDrawArrays(GL_TRIANGLES,0,3) en glDrawArrays(GL_TRIANGLES,0,6)
			qui permet la réalisation des 2 triangles
			
			Implementé pour indiquer qu'il faut relier les 3 vertex position (sommets) suivants.
			
Question 8.
	VBO: Les VBO sont une méthode qui permet d'envoyer des données 3D ( couleur et autre ) vers la carte graphique
	VAO: Les Vertex Array Object (ou VAO) sont des objets OpenGL relativement proches des Vertex Buffer Object (VBO) et font donc à peu près la même chose : stocker des informations sur la carte graphique.
	Program Shader: C'est un programme pour paramétrer une partie du processus de rendu réalisé par une carte graphique.
	
Question 9.
	Le premier triangle est tracé dans le sens inverse des aiguilles d'une montre en partant d'en bas à gauche du vertex 0 vers 1 puis 2
	Le deuxieme triangle est tracé dans le sens des aiguilles d'une montre en partant du sommet haut gauche du vertex 3 vers 4 puis 5
	
Question 12.
	2 vertex ont été échangé d'où une modification des position et un rendu ... qui part dans tous les sens. (voir snapshot)
	
Question 13.
	Pour récupérer le même rendu que précédent il faudrait tracer dans l'ordre : 0 -> 3 -> 2 -> 5 -> 1 -> 4
	
Question 15.
	Les couleurs sont directement associé au vertex donc si on modifie l'ordre de traitement des vertex ont ne change pas leur couleur associé.
	
Question 16.
	La couleur "rouge" est associé au vertex 5/ La couleur "vert" est associé au vertex 2
	
Question 20.
	Snapshot pris.
	
Question 23.
	Remarque : J'ai juste un doute sur ma fonction car la démarquation des couleurs n'est pas comme l'exemple ...

Question 24.
	Testez - ok