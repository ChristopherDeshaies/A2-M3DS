#version 130
        
in vec3 position;
/* color */
in vec4 fcolor;
out vec4 fColor;
/* coef */
uniform float coeff;

/* q25 */
in vec2 texCoord;
out vec2 fTexCoord;

void main() {
    //gl_Position=vec4(position,1.0);

    /* question 24 */
    vec3 newPosition = position*coeff;
    gl_Position=vec4(newPosition,1.0);

    fColor = fcolor;
    /* q25 */
    fTexCoord=texCoord;

}
