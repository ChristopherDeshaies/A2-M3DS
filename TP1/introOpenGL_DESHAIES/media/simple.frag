#version 130

out vec4 fragColor;
in vec4 fColor;

/* q25 */
in vec2 fTexCoord;
uniform sampler2D texture;
uniform float coeff;

void main() {
    //fragColor=vec4(1,0,0.6,1);
    fragColor=fColor;
    /* q25 */
    fragColor=texture2D(texture,fTexCoord);
    //q32
    // rouge de la texture multiplié par le rouge de fColor, idem pour green, et blue.
    // fragColor=texture2D(texture,fTexCoord)*fColor;
    // fColor est la couleur interpolée aux sommets(questions précédentes)

    //q33
    //fragColor=texture2D(texture,fTexCoord)*fColor.b;
    //coeff = uniform passée par l'application (questions précédentes.
    //fragColor.g*=(1.0-coeff);

}
