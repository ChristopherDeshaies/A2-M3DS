#include "GLApplication.h"

#include <iostream>

using namespace std;

GLApplication::~GLApplication() {
}

GLApplication::GLApplication() {
 /* _trianglePosition = {
    -0.8,-0.5,0.0, // vertex 0
    -0.2,-0.5,0.0, // 1
    -0.5,0.5,0.0,  // 2

    0.2,0.5,0.0,  // 3
    0.8,0.5,0.0,  // 4
    0.5,-0.5,0.0  // 5
  };*/


  _triangleColor = {
    0.3,0,0.6,1,
    0.3,0,0.6,1,
    0.0,0.9,0.0,1,

    0.0,0.5,0.6,1,
    0.0,0.5,0.6,1,
    0.9,0.0,0.0,1
  };



  /* question 12 */
 /*_trianglePosition = { -0.8,-0.5,0.0, // vertex 0 anciennement vertex 0
                       0.8,0.5,0.0, // 1 anciennement 4
                       -0.5,0.5,0.0, // 2 anciennement 2
                       -0.2,-0.5,0.0, // 3 anciennement 1
                       0.5,-0.5,0.0, // 4 anciennement 5
                       0.2,0.5,0.0 // 5 anciennement 3
                     };*/

 /* question 16 */
 //_trianglePosition = { -0.8,-0.8,0.0, 0.8,0.8,0.0, 0.0,0.2,0.0, -0.8,0.8,0.0, 0.8,-0.8,0.0, 0.0,0.2,0.0 };

 /* question 14 */
 /*_element = {
     0, 3, 2, 5, 1, 4
 };*/

 /* question 17 */
 /*_trianglePosition = { -0.8,-0.8,0.0,
                       -0.6,0.8,0.0,
                       -0.4,-0.6,0.0,
                       -0.2,0.6,0.0,
                       0.0,-0.8,0.0,
                       0.2,0.8,0.0,
                       0.4,-0.6,0.0,
                       0.6,0.6,0.0,
                       0.8,-0.8,0.0 };*/

 /* question 20 */
 /*_trianglePosition = { -0.8,-0.8,0.0,
                       -0.8,0.8,0.0,
                       -0.6,-0.8,0.0,
                       -0.6,0.8,0.0,
                       -0.4,-0.8,0.0,
                       -0.4,0.8,0.0,
                       -0.2,-0.8,0.0,
                       -0.2,0.8,0.0 };


 // tous les sommets à rouge :
 _triangleColor.clear();
 for(unsigned int i=0;i<9;++i) {
     _triangleColor.push_back(1);
     _triangleColor.push_back(0);
     _triangleColor.push_back(0);
     _triangleColor.push_back(1); }*/


 /* question 16 */
// _element = { 0, 3, 2, 2, 1, 4 };

 /* question 20 */
 //initStrip(15,-0.4,0.4,-0.4,0.4);


 //q25
 //init du coeff
 _coeff=1.0;
 // indique le sens pour l'update de la taille du cercle (1 pour grandir et 0 pour rétrecir)
 _sens=1;


  _trianglePosition = {
      // rectangle tracé avec TRIANGLE_STRIP
      -0.6,-0.8,0,
      -0.6,0.8,0,
      0.6,-0.8,0,
      0.6,0.8,0 };

  _triangleColor = {
      // tous les sommets en rouge
      1,0,0,1,
      1,0,0,1,
      1,0,0,1,
      1,0,0,1,
  };

  /* question 27 */
  _triangleTexCoord = {
      // coordonnées de texture en chaque sommet
      0,0,
      0,1,
      1,0,
      1,1

  };

  initRing(100,0.2,1);

}




/** ********************************************************************** **/
void GLApplication::initialize() {
  // appelée 1 seule fois à l'initialisation du contexte
  // => initialisations OpenGL
  glClearColor(1,1,1,1);

  glLineWidth(2.0);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  /* question 18 */
  //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

  _shader0=initProgram("simple");


  initTriangleBuffer();
  initTriangleVAO();
  initTexture();


}

// question 21
void GLApplication::initStrip(int nbSlice,float xmin,float xmax,float ymin,float ymax){
    _trianglePosition.clear();
    _triangleColor.clear();

    if(nbSlice>0){

        float ecart = (xmax-xmin)/nbSlice;
        float ecartCouleur = (1.0/(nbSlice+1));

        for(int i=0;i<=((2*nbSlice)+1);i++){
            if(i%2 == 0){
                _trianglePosition.push_back(xmin+(ecart*(i/2)));
                _trianglePosition.push_back(ymin);
                _trianglePosition.push_back(0);

                _triangleColor.push_back(0);
                _triangleColor.push_back(0+(ecartCouleur*(i/2)));
                _triangleColor.push_back(0);
                _triangleColor.push_back(1);
            }else{
                _trianglePosition.push_back(xmin+(ecart*(i/2)));
                _trianglePosition.push_back(ymax);
                _trianglePosition.push_back(0);

                _triangleColor.push_back(0);
                _triangleColor.push_back(0);
                _triangleColor.push_back(1-(ecartCouleur*(i/2)));
                _triangleColor.push_back(1);
            }
        }
    }

}

/* q20 *//*
void GLApplication::initRing(int nbSlice,float r0,float r1){
    _trianglePosition.clear();
    _triangleColor.clear();

    float stepTheta=2.0*3.14159/nbSlice;
    float theta=0.0;
    double x,y;
    float ecartCouleur = (1.0/(nbSlice+1));

    for(int i=0;i<=((2*nbSlice)+2);i++){

        if(i%2 == 0){

            if(i>0){
                theta+=stepTheta;
            }

            x=r0*cos(theta);
            y=r0*sin(theta);
            _trianglePosition.push_back(x);
            _trianglePosition.push_back(y);
            _trianglePosition.push_back(0);

            _triangleColor.push_back(0);
            _triangleColor.push_back(0+(ecartCouleur*(i/2)));
            _triangleColor.push_back(0);
            _triangleColor.push_back(1);


        }else{
            x=r1*cos(theta);
            y=r1*sin(theta);
            _trianglePosition.push_back(x);
            _trianglePosition.push_back(y);
            _trianglePosition.push_back(0);

            _triangleColor.push_back(0);
            _triangleColor.push_back(0);
            _triangleColor.push_back(1-(ecartCouleur*(i/2)));
            _triangleColor.push_back(1);
        }
    }
}*/

/* q30 */
void GLApplication::initRing(int nbSlice,float r0,float r1){
    _trianglePosition.clear();
    _triangleColor.clear();

    float stepTheta=2.0*3.14159/nbSlice;
    float theta=0;
    double x,y;
    float xi = 0.0;
    float zi = 1.0/nbSlice;

    for(int i=0;i<=((2*nbSlice)+2);i++){

        if(i%2 == 0){

            if(i>0){theta+=stepTheta;}

            x=r1*cos(theta);
            y=r1*sin(theta);
            _trianglePosition.push_back(x);
            _trianglePosition.push_back(y);
            _trianglePosition.push_back(0);


                _triangleTexCoord.push_back(xi);
                _triangleTexCoord.push_back(0);


            //_triangleTexCoord.push_back(0.5*x+0.5);
            //_triangleTexCoord.push_back(0.5*y+0.5);

           //q32
           // _triangleColor.push_back(0);
           // _triangleColor.push_back(0);
           // _triangleColor.push_back(1);


        }else{

            x=r0*cos(theta);
            y=r0*sin(theta);
            _trianglePosition.push_back(x);
            _trianglePosition.push_back(y);
            _trianglePosition.push_back(0);


               _triangleTexCoord.push_back(xi);
               _triangleTexCoord.push_back(1);


            //_triangleTexCoord.push_back(0.5*x+0.5);
            //_triangleTexCoord.push_back(0.5*y+0.5);


            //   _triangleColor.push_back(0);
            //   _triangleColor.push_back(1);
            //   _triangleColor.push_back(0);


            //retour à un vect inférieur -> (i,0)
            xi += zi;
        }

    }
}


void GLApplication::resize(int width,int height) {
  // appelée à chaque dimensionnement du widget OpenGL
  // (inclus l'ouverture de la fenêtre)
  // => réglages liés à la taille de la fenêtre
  glViewport(0,0,width,height);
  // ...
}

void GLApplication::update() {
  // appelée toutes les 20ms (60Hz)
  // => mettre à jour les données de l'application
  // avant l'affichage de la prochaine image (animation)
  // ...

    // question 24
   /* if(_sens==1){
       _coeff=_coeff+0.02;
       if(_coeff>=1.0){
           _sens=0;
       }
    }else{
       _coeff=_coeff-0.02;
       if(_coeff<=0.0){
           _sens=1;
       }
    }*/

}

void GLApplication::draw() {
  // appelée après chaque update
  // => tracer toute l'image
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(_shader0);
  glUniform1f(glGetUniformLocation(_shader0,"coeff"),_coeff);
  glBindVertexArray(_triangleVAO);

  /* question 25 */
  glActiveTexture(GL_TEXTURE0); // on travaille avec l'unité de texture 0
  glBindTexture(GL_TEXTURE_2D,_textureId); // l'unité de texture 0 correspond à la texture _textureId (image lagoon).

  glUniform1f(glGetUniformLocation(_shader0,"texture"),0); // on affecte la valeur du sampler2D du fragment shader à l'unité de texture 0.


  //glDrawArrays(GL_TRIANGLES,0,3);
  //** question 7 **/
  //glDrawArrays(GL_TRIANGLES,0,6);
  //** question 14 **/
  //glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
  //** question 17 **/
  //glDrawArrays(GL_TRIANGLES,0,9);
  /* question 19 */
  //glDrawArrays(GL_TRIANGLE_STRIP,0,8);
  /* question 21 */
  glDrawArrays(GL_TRIANGLE_STRIP,0,_trianglePosition.size()/3);

  glBindVertexArray(0);
  glUseProgram(0);


  snapshot(); // capture opengl window if requested
}

/** ********************************************************************** **/
/** i = button number, s = button text
 */
void GLApplication::leftPanel(int i,const std::string &s) {
  cout << "GLApplication : button clicked " << i << " " << s << endl;
  /*
  switch (i) {
    case 0:menu0();break;
    case 1:menu1();break;
  }
  */
}




/** *********************************************************** **/
GLuint GLApplication::initProgram(const std::string &filename) {
  GLuint program;
  int infoLength; // for message error

  string vertexSource=p3d::readTextFile(filename+".vert");
  string fragmentSource=p3d::readTextFile(filename+".frag");

  program=glCreateProgram();
  GLuint vertexShader=glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
  glAttachShader(program,vertexShader);
  glAttachShader(program,fragmentShader);

  const char *source;
  source=vertexSource.c_str();
  glShaderSource(vertexShader,1,&source,NULL);
  source=fragmentSource.c_str();
  glShaderSource(fragmentShader,1,&source,NULL);

  GLint ok;
  glCompileShader(vertexShader);
  glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&ok);
  if (!ok) {
    glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&infoLength);
    cout << "=============================" << endl;
    cout << "GLSL Error : " << endl;
    char *info=new char[infoLength];
    glGetShaderInfoLog(vertexShader,infoLength,NULL,info);
    cout << info;
    cout << endl;
    delete info;
    throw ErrorD("Vertex Shader compilation error");
  }

  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&ok);
  if (!ok) {
    glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&infoLength);
    cout << "=============================" << endl;
    cout << "GLSL Error : " << endl;
    char *info=new char[infoLength];
    glGetShaderInfoLog(fragmentShader,infoLength,NULL,info);
    cout << info;
    cout << endl;
    delete info;
    throw ErrorD("Vertex Shader compilation error");
  }

  glBindAttribLocation(program,0,"position");
  glBindAttribLocation(program,1,"color");
  glBindAttribLocation(program,2,"texCoord");

  glLinkProgram(program);
  glGetProgramiv(program,GL_LINK_STATUS,&ok);
  if (!ok) {
    char *info=new char[infoLength];
    glGetProgramInfoLog(program,infoLength,NULL,info);
    cout << "Info Log :" << endl;
    cout << info;
    cout << endl;
    delete info;
    throw ErrorD("Program Shader : link error (varyings ok ?)");
  }

  return program;
}


void GLApplication::initTexture() {
    QImage img;
    img.load("../media/lagoon.jpg");
    img=img.convertToFormat(QImage::Format_ARGB32).mirrored();

    glGenTextures(1,&_textureId);
    glBindTexture(GL_TEXTURE_2D,_textureId);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img.width(),img.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,img.bits());



    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
}


void GLApplication::initTriangleBuffer() {

  glGenBuffers(1,&_trianglePositionBuffer);
  glBindBuffer(GL_ARRAY_BUFFER,_trianglePositionBuffer);
  glBufferData(GL_ARRAY_BUFFER,_trianglePosition.size()*sizeof(float),_trianglePosition.data(),GL_STATIC_DRAW);

  /* question 10 - buffer pour la couleur */
  glGenBuffers(1,&_triangleColorBuffer);
  glBindBuffer(GL_ARRAY_BUFFER,_triangleColorBuffer);
  glBufferData(GL_ARRAY_BUFFER,_triangleColor.size()*sizeof(float),_triangleColor.data(),GL_STATIC_DRAW);

  /* question 14 - buffer pour les éléments */
  glGenBuffers(1,&_elementBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,_element.size()*sizeof(int),_element.data(),GL_STATIC_DRAW);

  /* question 25 - buffer pour le rectangle */
  glGenBuffers(1,&_triangleTexCoordBuffer);
  glBindBuffer(GL_ARRAY_BUFFER,_triangleTexCoordBuffer);
  glBufferData(GL_ARRAY_BUFFER,_triangleTexCoord.size()*sizeof(float),_triangleTexCoord.data(),GL_STATIC_DRAW);


}


void GLApplication::initTriangleVAO() {
  glGenVertexArrays(1,&_triangleVAO);
  glBindVertexArray(_triangleVAO);

  glBindBuffer(GL_ARRAY_BUFFER,_trianglePositionBuffer);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);

  /* question 10 */
  glBindBuffer(GL_ARRAY_BUFFER,_triangleColorBuffer);
  glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,0,0);

  /* question 14 */
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);

  /* question 25 */
  glBindBuffer(GL_ARRAY_BUFFER,_triangleTexCoordBuffer);
  glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,0,0);

  glEnableVertexAttribArray(0);
  /* question 10 */
  glEnableVertexAttribArray(1);
  /* question 25 */
  glEnableVertexAttribArray(2);

  glBindVertexArray(0);
}



