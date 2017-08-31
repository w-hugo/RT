#ifndef GUI_H
# define GUI_H

#include "../../../includes/rt.h"

#define UNUSED(a) (void)a


#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

#ifdef __APPLE__
#define NK_SHADER_VERSION "#version 150\n"
#else
#define NK_SHADER_VERSION "#version 300 es\n"
#endif

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

struct nk_glfw_vertex {
	float position[2];
	float uv[2];
	nk_byte col[4];
};

struct device {
	struct nk_buffer cmds;
	struct nk_draw_null_texture null;
	GLuint vbo, vao, ebo;
	GLuint prog;
	GLuint vert_shdr;
	GLuint frag_shdr;
	GLint attrib_pos;
	GLint attrib_uv;
	GLint attrib_col;
	GLint uniform_tex;
	GLint uniform_proj;
	GLuint font_tex;
};


void	ui_widget(struct nk_context *ctx, struct media *media, float height);
void	ui_header(struct nk_context *ctx, struct media *media, const char *title);
void	ui_widget_centered(struct nk_context *ctx, struct media *media, float height);
int		ui_piemenu(struct nk_context *ctx, struct nk_vec2 pos, float radius,
		struct nk_image *icons, int item_count);
void	ui_widget_small_button(struct nk_context *ctx, struct media *media, float height);
void
ui_widget_special_mode(struct nk_context *ctx, struct media *media, float height);
int
ui_widget_value_infos(struct nk_context *ctx, struct media *media, double *value, char *title);


/* ===============================================================
 *
 *                         DELETE OBJECTS
 *
 * ===============================================================*/

//int			remove_object(t_world *world, t_intersection *i);
void			remove_sphere(t_sphere **s, t_intersection *i);
void			remove_cone(t_cone **s, t_intersection *i);
void			remove_cylinder(t_cylinder **s, t_intersection *i);
void			remove_plane(t_plane **s, t_intersection *i);
int				mousepress_right(struct nk_context *ctx, t_world *world, struct nk_vec2 pos);

/* ===============================================================
 *
 *                          WINDOW POP UP
 *
 * ===============================================================*/

void	basic_demo(struct nk_context *ctx, struct media *media);
void	grid_demo(struct nk_context *ctx, struct media *media);
void	scene_parameters(struct nk_context *ctx, struct media *media, t_world *world);
void	render_demo(struct nk_context *ctx, struct media *media, int *a_h, t_world *world);

/* ===============================================================
 *
 *                          DEVICE INIT
 *
 * ===============================================================*/

void	device_shutdown(struct device *dev);
void	device_upload_atlas(struct device *dev, const void *image, int width, int height);
void 	device_init(struct device *dev);
void	set_up_global_state(struct device *dev, GLfloat ortho[4][4]);

/* ===============================================================
 *
 *                          OPENGL INIT
 *
 * ===============================================================*/

void	defaut_opengl_state();
void 	init_glfw_start(GLFWwindow **win, struct nk_context *ctx, t_screen *screen);
void 	error_callback(int e, const char *d);
void 	scroll_input(GLFWwindow *win, double _, double yoff);
void 	text_input(GLFWwindow *win, unsigned int codepoint);
void die(const char *fmt, ...);

struct nk_image icon_load(const char *filename);
void	loading_media(struct media *media, struct nk_font_atlas *atlas, struct nk_context *ctx, struct device *device);
void	device_draw(struct device *dev, struct nk_context *ctx, t_screen *screen, enum nk_anti_aliasing AA);
void	allocate_vertex_buffer(struct device *dev, enum nk_anti_aliasing AA, struct nk_context *ctx);
int	key_press(struct nk_context *ctx, t_world *world);
#endif