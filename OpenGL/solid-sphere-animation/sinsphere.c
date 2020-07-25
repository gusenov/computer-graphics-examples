/* sinsphere.c */


#include <GLUT/glut.h>

#include <stdlib.h>

#include <sys/time.h>
#include <math.h>

#define M_PI    3.1415926535897932384626433832795029L
#define M_PI_2  1.5707963267948966192313216916397514L

# define timersub(a, b, result)                                               \
  do {                                                                        \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;                             \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;                          \
    if ((result)->tv_usec < 0) {                                              \
      --(result)->tv_sec;                                                     \
      (result)->tv_usec += 1000000;                                           \
    }                                                                         \
  } while (0)

void idle(void);
void animate(float dT);
void display(void);
void init_sphere(unsigned int rings, unsigned int sectors);
void draw_sphere(void);

int main(int argc, char *argv[])
{    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("SinSphere");
    glutIdleFunc(idle);
    glutDisplayFunc(display);

    init_sphere(10, 30);

    glutMainLoop();

    return 0;
}

struct AnimationState
{
    float time;
        float sphere_speed;
    float sphere_path_radius;
    float sphere_path_bobbing;
    float sphere_position[3];
};

static struct AnimationState animation = {
    0.,
    0.1, 3., 1.,
    {1., 0., 0.}
};

void animate(float dT)
{
    animation.time += dT;

    animation.sphere_position[0] = animation.sphere_path_radius * cos(2*M_PI * animation.time * animation.sphere_speed);
    animation.sphere_position[1] = animation.sphere_path_bobbing * sin(2*M_PI * animation.time * 5 * animation.sphere_speed);
    animation.sphere_position[2] = animation.sphere_path_radius * sin(2*M_PI * animation.time * animation.sphere_speed);
}

GLfloat *sphere_vertices_normals;
unsigned int sphere_quads = 0;
GLushort *sphere_indices;

void init_sphere(unsigned int rings, unsigned int sectors)
{
    float const R = 1./(float)(rings-1);
    float const S = 1./(float)(sectors-1);
    int r, s;

    sphere_vertices_normals = malloc(sizeof(GLfloat)*3 * rings*sectors);

    GLfloat *v = sphere_vertices_normals;
    for(r = 0; r < rings; r++) for(s = 0; s < sectors; s++) {
        float const y = sin( -M_PI_2 + M_PI * r * R );

        float const x = cos(2*M_PI * s * S) * sin( M_PI * r * R );

        float const z = sin(2*M_PI * s * S) * sin( M_PI * r * R );

        v[0] = x;
        v[1] = y;
        v[2] = z;

        v+=3;
    }

    sphere_indices = malloc(sizeof(GLushort) *  rings * sectors * 4);
    GLushort *i = sphere_indices;
    for(r = 0; r < rings; r++) for(s = 0; s < sectors; s++) {
        *i++ = r * sectors + s;
        *i++ = r * sectors + (s+1);
        *i++ = (r+1) * sectors + (s+1);
        *i++ = (r+1) * sectors + s; 
        sphere_quads++;
    }
}

void draw_sphere()
{
    glTranslatef(animation.sphere_position[0], animation.sphere_position[1], animation.sphere_position[2]);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, sphere_vertices_normals);
    glNormalPointer(GL_FLOAT, 0, sphere_vertices_normals);
    glDrawElements(GL_QUADS, sphere_quads*4, GL_UNSIGNED_SHORT, sphere_indices);
}

void idle()
{
    glutPostRedisplay();
}

static GLfloat const light_pos[4] = {-1., 1., 1., 0.};
static GLfloat const light_color[4] = {1., 1., 1., 1.};

void display()
{
    static struct timeval delta_T = {0., 0.};
    struct timeval time_frame_begin, time_frame_end;

    int win_width, win_height;
    float win_aspect;

    gettimeofday(&time_frame_begin, 0);

    animate(delta_T.tv_sec + delta_T.tv_usec * 1.e-6);

    win_width = glutGet(GLUT_WINDOW_WIDTH);
    win_height = glutGet(GLUT_WINDOW_HEIGHT);
    win_aspect = (float)win_width/(float)win_height;

    glViewport(0, 0, win_width, win_height);
    glClearColor(0.6, 0.6, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-win_aspect, win_aspect, -1., 1., 1., 10.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-5.5);

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glPushMatrix();

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    draw_sphere();

    glPopMatrix();

    glutSwapBuffers();

    gettimeofday(&time_frame_end, 0);
    timersub(&time_frame_end, &time_frame_begin, &delta_T);

}