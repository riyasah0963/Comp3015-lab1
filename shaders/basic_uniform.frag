#version 460 core

in vec3 Position;
in vec3 Normal;

out vec4 FragColor;

struct LightInfo {
    vec4 Position;
    vec3 Direction;
    float Cutoff;
    vec3 La;
    vec3 Ld;
    vec3 Ls;
};

struct MaterialInfo {
    vec3 Ka;
    vec3 Kd;
    vec3 Ks;
    float Shininess;
};

uniform LightInfo Light;
uniform MaterialInfo Material;

vec3 phongModel()
{
    vec3 n = normalize(Normal);
    vec3 s = normalize(vec3(Light.Position) - Position);
    vec3 v = normalize(-Position);

    float spotFactor = dot(normalize(-s), normalize(Light.Direction));

    vec3 ambient = Light.La * Material.Ka;

    if (spotFactor < Light.Cutoff)
        return ambient;

    float sDotN = max(dot(s, n), 0.0);
    vec3 diffuse = Light.Ld * Material.Kd * sDotN;

    vec3 r = reflect(-s, n);
    vec3 spec = vec3(0.0);

    if (sDotN > 0.0)
        spec = Light.Ls * Material.Ks *
               pow(max(dot(r, v), 0.0), Material.Shininess);

    return ambient + spotFactor * (diffuse + spec);
}

void main()
{
    vec3 color = phongModel();
    FragColor = vec4(color, 1.0);
}