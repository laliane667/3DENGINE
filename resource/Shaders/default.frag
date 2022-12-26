#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;
in vec3 Normal;
in vec3 crntPos;
in vec2 texCoord;

// Gets the Texture Unit from the main function
uniform sampler2D diffuse0;
uniform sampler2D specular0;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;


vec4 pointLight()
{
	// used in two variables so I calculate it here to not have to do it twice
	vec3 lightVec = lightPos - crntPos;

	// intensity of light with respect to distance
	float dist = length(lightVec);
	float a = 0.05; //3.0
    float b = 0.01f; //0.7
	float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);

	// ambient lighting
	float ambient = 0.20f;

	// diffuse lighting


	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightVec);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	float specular = 0.0;

	if(diffuse != 0)
    {
        	// specular lighting
        float specularLight = 0.50f;
        vec3 viewDirection = normalize(camPos - crntPos);
        vec3 reflectionDirection = reflect(-lightDirection, normal);

        vec3 halfWayVect = normalize(viewDirection + lightDirection);

        float specAmount = pow(max(dot(normal, halfWayVect), 0.0f), 16);
        specular = specAmount * specularLight;
    }

	return (texture(diffuse0, texCoord) * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten) * lightColor;
}

vec4 directLight()
{
    vec3 lightVec = lightPos - crntPos;
    float dist = length(lightVec);
    float a = 0.05; //3.0
    float b = 0.01f; //0.7
    float inten = 1.0f/(a * dist*dist + b * dist + 1.0f);
    float ambiant = 0.20f;

    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(vec3(1.0f, 1.0f, 0.0f));
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - crntPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);

    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
    float specular = specAmount * specularLight;

	return texture(diffuse0, texCoord) * lightColor * ( diffuse * inten + ambiant) + texture(specular0, texCoord).r * specular * inten;
}

vec4 spotLight()
{
    float outerCone = 0.90f;
    float innerCone = 0.95f;

    float ambiant = 0.20f;

    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - crntPos);
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - crntPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);

    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
    float specular = specAmount * specularLight;

    float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDirection);
    float inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);

	return texture(diffuse0, texCoord) * lightColor * ( diffuse * inten + ambiant) + texture(specular0, texCoord).r * specular * inten;
}

void main()
{
	//FragColor = directLight();
	FragColor = pointLight();
	// FragColor = spotLight();
}
