/*
** rt.h for RTV2 in /home/rotaru_i/Coding/LibLap/tests/inc
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Apr 26 20:53:49 2016 Iulian Rotaru
** Last update Sun May 22 21:09:54 2016 
*/

#ifndef RT_H_
# define RT_H_

# include <lapin.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include <pthread.h>
# include <math.h>
# include <stdio.h>

# define MAX_BLUR (20)
# define X_MAX (1400)
# define Y_MAX (976)
# define FIG_NB (6)
# define OK (0)
# define KO (-1)
# define LETTER_X (5)
# define LETTER_Y (7)
# define MAX_REMIX (3)
# define EYE_ERROR "\033[31;1mWarning: multiple eye elements "
# define EYE_NEXT EYE_ERROR"in .ini file, saving first only.\n\033[0m"

typedef struct		s_moy
{
  t_color		up;
  t_color		down;
  t_color		left;
  t_color		right;
  t_color		center;
  t_color		upl;
  t_color		upr;
  t_color		downl;
  t_color		downr;
  t_color		end;
}			t_moy;

typedef struct		s_text
{
  int			police_size;
  unsigned int		fg;
  t_bunny_position	pos;
  int			x;
  int			y;
}			t_text;

typedef struct		s_area_text
{
  int			x;
  int			y;
  int			i;
  int			j;
  int			ratio;
  t_bunny_position	blit;
  unsigned int		*ptrr;
  unsigned int		*ptr;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*extract;
  t_bunny_position	*area;
  t_text		*text;
}			t_area_text;

typedef struct	s_data t_data;

typedef struct		s_vec
{
  double		x;
  double		y;
  double		z;
}			t_vec;

typedef enum		e_type
  {
    SPHERE = 42,
    PLANE,
    CONE,
    CYLINDRE,
    LIGHT,
    CUBE
  }			t_type;

typedef struct		s_fig
{
  char			lim[6];
  char			alpha;
  char			shine;
  char			refl;
  char			ambiant;
  int			height;
  int			angle;
  int			idx;
  int			type;
  t_color		rgb;
  char			*name;
  double		radius;
  t_vec			pos;
  t_vec			nvec;
  t_vec			dvec;
  t_vec			rot;
  t_vec			max;
  t_vec			min;
  t_vec			size;
  struct s_fig		*next;
}			t_fig;

typedef struct		s_eye
{
  t_vec			pos;
  t_vec			dir;
  t_vec			upvec;
  t_vec			rightvec;
  int			filled;
  double		scr_dist;
}			t_eye;

typedef struct		s_save
{
  int			mode;
  char			*name;
  int			on;
}			t_save;

typedef struct		s_menu
{
  t_color		render_butt;
  t_save		save;
  int			menu_state;
  int			menu_status;
  t_bunny_picture	*pause;
  t_bunny_pixelarray	*butts[9];
  int			focus;
  int			obj_idx;
  t_fig			*fig_focus;
  int			scroll;
}			t_menu;

typedef struct		s_thd
{
  int			line;
  int			limits[2];
  int			refl;
  int			alpha;
  pthread_t		thread;
  t_data		*data;
  int			thread_state;
  int			idx;
  int			t;
}			t_thd;

typedef struct		s_edit
{
  int			on;
  char			buffer[4096];
  int			input_mode;
  void			*edit;
  int			idx;
}			t_edit;

struct			s_data
{
  int			blur_extremum[2];
  int			blur;
  int			blur_dist;
  t_bunny_position	bl;
  int			*dists;
  int			baw;
  int			aalias;
  pthread_mutex_t	lock;
  int			add;
  int			add_select;
  t_edit		edit;
  int			fig_nb;
  t_eye			eye;
  t_bunny_pixelarray	*signature;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*menu_tabs[3];
  char			first_call;
  int			thread_nb;
  int			render_state;
  int			exit;
  char			thread_changed;
  double		thread_changed_speed;
  t_menu		menu;
  t_fig			*fig;
  t_fig			*lights;
  char			*file_name;
  t_bunny_ini		*ini;
  t_thd			*threads;
  char			light;
  char			shine;
  char			refl;
  char			alpha;
  t_bunny_window	*win[2];
  t_bunny_pixelarray	*pix[2];
};

typedef struct		s_eko
{
  t_vec			pos;
  double		t;
  const t_fig		*fig;
  t_color		col;
}			t_eko;

typedef struct		s_fct
{
  char			*name;
  int			(*fct)(t_bunny_ini_scope *, t_data *);
}			t_fct;

typedef struct		s_eg
{
  t_fig			*tmp;
  t_vec			rot;
  t_eye			new_eye;
  t_fig			center;
  t_eko			ret;
  t_eko			cmp;
}			t_eg;

typedef struct		s_cub
{
  double		tmin;
  double		tmax;
  double		tymin;
  double		tymax;
  double		tzmin;
  double		tzmax;
  t_eko			ret;
}			t_cub;

/*
** CPP
*/

void		my_set_win_position(const t_bunny_window *w,
				    const t_bunny_position *p);
/*
** INI Loaders
*/

void		place_new(t_data *data,
			  t_fig *new);
void		place_new_light(t_data *data,
				t_fig *new);
int		load_obj_hub(t_bunny_ini_scope *scope,
			     t_data *data);
int		load_cylindre(t_bunny_ini_scope *scope,
			      t_data *data);
int		load_sphere(t_bunny_ini_scope *scope,
			    t_data *data);
int		load_plane(t_bunny_ini_scope *scope,
			   t_data *data);
int		load_light(t_bunny_ini_scope *scope,
			   t_data *data);
int		load_cone(t_bunny_ini_scope *scope,
			  t_data *data);
int		load_eye(t_bunny_ini_scope *scope,
			 t_data *data);
int		load_cube(t_bunny_ini_scope *scope,
			  t_data *data);
/*
** MENU
*/

void		*menu_loop(t_data *data);
/*
** MISC
*/

int		nbr(const char *str);
int		my_strcmp_start(const char *one,
				const char *two);
int		putst_err(int fd,
			  char *str,
			  int ret);
int		isnum(const char *str);
void		*callo_c(size_t size);
void		mset(void *data,
		     size_t size);
int		cmp(const char *one,
		    const char *two);
int		len(const char *str);
unsigned int	color_mixer(unsigned int one,
			    unsigned int add);
void		blitstr(char *str,
			t_bunny_pixelarray *dest,
			t_bunny_picture *font,
			t_text *text);
void		main_boucle(t_area_text *v);
void		ratio_setter(int *ratio,
			     t_text *text);
void		set_start_nb(t_bunny_position *pos,
			     t_text *text,
			     int ratio,
			     int j);
void		my_blitstr(char *str,
			   t_bunny_pixelarray *pix,
			   t_bunny_pixelarray *text_pix,
			   t_text *text);
void		my_blitnbr(int nb,
			   t_bunny_pixelarray *pix,
			   t_bunny_pixelarray *text_pix,
			   t_text *text);
int		len(const char *str);
char		*sdup(const char *str);
void		fill(t_bunny_pixelarray *pix,
		     unsigned int color);
void		my_bunny_blit(t_bunny_pixelarray *big,
			      t_bunny_pixelarray *small,
			      t_bunny_position *pos,
			      int mode);
void		threads_animation(t_data *data,
				  int mode);
/*
** RT
*/

void			*rt_start(void *send);
double			norm(const t_vec *);
double			scal(const t_vec *,
			     const t_vec *);
double			angle_vec(const t_vec *,
				  const t_vec *);
void			deter_corner(t_thd *,
				     t_vec *);
t_vec			get_ray(t_bunny_position *,
				t_thd *,
				t_vec *);
t_eko			dcircle(const t_vec *,
				const t_eye *,
				const t_fig *);
t_eko			plane(const t_vec *,
			      const t_eye *,
			      const t_fig *);
t_eko			cube(const t_vec *,
			     const t_eye *,
			     const t_fig *);
t_eko			cone(const t_vec *,
			     const t_eye *,
			     const t_fig *);
t_eko			cylinder(const t_vec *,
				 const t_eye *,
				 const t_fig *);
void			benard_cyl(t_vec **,
				   t_fig *,
				   t_color *,
				   const t_fig *);
void			benard_sphere(t_vec **,
				      t_fig *,
				      t_color *,
				      const t_fig *);
void			benard_cone(t_vec **,
				    t_fig *,
				    t_color *,
				    const t_fig *);
void			benard_plan(t_vec **,
				    t_fig *,
				    t_color *,
				    const t_fig *);
void			benard_cube(t_vec **,
				    t_fig *,
				    t_color *,
				    const t_fig *);
unsigned int		apply_light(t_eko *,
				    t_thd *);
unsigned int		send_ray(const t_vec *,
				 t_thd *,
				 t_eye *,
				 const t_fig *);
void			menu_baw(t_data *data,
				 t_text *text);
void			menu_shine(t_data *data,
				   t_text *text);
void			menu_light(t_data *data,
				   t_text *text);
void			make_square(t_bunny_pixelarray *pix,
				    t_bunny_position *pos,
				    t_bunny_position *size,
				    unsigned int color);
void			fill(t_bunny_pixelarray *pix,
			     unsigned int color);
void			circle(t_bunny_pixelarray *pix,
			       t_bunny_position *rep,
			       int *radius,
			       unsigned int color);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);
void			menu_alpha(t_data *data,
				   t_text *text);
void			menu_refl(t_data *data,
				  t_text *text);
void			menu_blur(t_data *data,
				  t_text *text);
void			render_down_one(t_bunny_position *pos,
					t_color *colors,
					int *round);
void			render_animation_right(t_data *data);
void			render_right_one(t_bunny_position *pos,
					 t_color *colors,
					 int *round);
void			render_animation_left(t_data *data);
void			render_left_one(t_bunny_position *pos,
					t_color *colors,
					int *round);
void			threads_animation(t_data *data,
					  int mode);
void			case_multi_thread(t_data *data,
					  int increm,
					  double round,
					  t_bunny_position *pos);
void			set_pos(t_bunny_position *pos,
				double ecart,
				double round);
void			case_one_thread(t_data *data);
void			render_animation_down(t_data *data);
void			menu_saver_on(t_data *data,
				      t_text *text);
void			menu_saver_ini(t_data *data,
				       t_text *text,
				       t_bunny_position *pos);
void			menu_saver_img(t_data *data,
				       t_text *text,
				       t_bunny_position *pos);
void			menu_saver(t_data *data,
				   t_text *text);
void			menu_render(t_data *data,
				    t_text *text);
void			menu_threads_nb(t_data *data,
					t_text *text);
void			menu_threads_butts(t_data *data,
					   t_text *text,
					   t_bunny_position *pos);
void			plus_butt(t_data *data,
				  t_text *text);
void			min_butt(t_data *data,
				 t_text *text);
void			menu_menu(t_data *data);
void			aff_static_icons(t_data *data);
void			aff_arrows(t_data *data);
void			aff_eye(t_data *data);
void			empty_square(t_bunny_pixelarray *pix,
				     t_bunny_position *pos,
				     unsigned int *color,
				     int mode);
void			menu_threads(t_data *data);
void			aff_objs(t_data *data);
void			aff_figs(t_data *data,
				 t_bunny_position *pos,
				 int i,
				 t_fig *tmp);
void			aff_one_obj(t_data *data,
				    t_bunny_position *targ,
				    t_fig *fig);
t_bunny_pixelarray	*get_pix_obj(t_data *data,
				     t_fig *fig);
t_bunny_pixelarray	*get_pix_end(t_data *data,
				     t_fig *fig);
void			aff_sphere_refl(t_data *data,
					t_text *text,
					t_fig *fig);
void			aff_sphere_rgb(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_sphere_pos(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_eye_obj(t_data *data,
				    t_text *text);
void			aff_eye_dir(t_data *data,
				    t_text *text);
void			aff_sphere(t_data *data,
				   t_text *text,
				   t_fig *fig);
void			aff_sphere_limit(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_sphere_radius(t_data *data,
					  t_text *text,
					  t_fig *fig);
void			aff_sphere_shine(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_sphere_alpha(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_cube_shine(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_cube_alpha(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_cube_refl(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_cube_rgb(t_data *data,
				     t_text *text,
				     t_fig *fig);
void			aff_cube_pos(t_data *data,
				     t_text *text,
				     t_fig *fig);
void			aff_light_ambiant(t_data *data,
					  t_text *text,
					  t_fig *fig);
void			aff_light_rgb(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_light_pos(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_cube(t_data *data,
				 t_text *text,
				 t_fig *fig);
void			aff_cube_size(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_cylindre_alpha(t_data *data,
					   t_text *text,
					   t_fig *fig);
void			aff_cylindre_refl(t_data *data,
					  t_text *text,
					  t_fig *fig);
void			aff_cylindre_rgb(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_cylindre_pos(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_light(t_data *data,
				  t_text *text,
				  t_fig *fig);
void			aff_cylindre_lim(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_cylindre_dvec(t_data *data,
					  t_text *text,
					  t_fig *fig);
void			aff_cylindre_rot(t_data *data,
					 t_text *text,
					 t_fig *fig);
void			aff_cylindre_radius(t_data *data,
					    t_text *text,
					    t_fig *fig);
void			aff_cylindre_shine(t_data *data,
					   t_text *text,
					   t_fig *fig);
void			aff_cone_alpha(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_cone_refl(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_cone_rgb(t_data *data,
				     t_text *text,
				     t_fig *fig);
void			aff_cone_pos(t_data *data,
				     t_text *text,
				     t_fig *fig);
void			aff_cylindre(t_data *data,
				     t_text *text,
				     t_fig *fig);
void			aff_cone(t_data *data,
				 t_text *text,
				 t_fig *fig);
void			aff_cone_height(t_data *data,
					t_text *text,
					t_fig *fig);
void			aff_cone_dvec(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_cone_rot(t_data *data,
				     t_text *text,
				     t_fig *fig);
void			aff_cone_angle(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_plane_shine(t_data *data,
					t_text *text,
					t_fig *fig);
void			aff_plane_alpha(t_data *data,
					t_text *text,
					t_fig *fig);
void			aff_plane_refl(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_plane_rgb(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_plane_pos(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_plane_nvec(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_plane_dvec(t_data *data,
				       t_text *text,
				       t_fig *fig);
void			aff_plane_rot(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_plane_max(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_plane_min(t_data *data,
				      t_text *text,
				      t_fig *fig);
void			aff_plane(t_data *data,
				  t_text *text,
				  t_fig *fig);
void			add_menu_con_cyl(t_data *data,
					 t_text *text);
void			aff_focused(t_data *data,
				    t_text *text);
void			aff_delete(t_data *data,
				   t_text *text);
void			aff_add(t_data *data,
				t_text *text);
void			fade_away(t_data *data);
void			menu_obj(t_data *data);
void			add_menu(t_data *data,
				 t_text *text);
void			add_menu_end(t_data *data,
				     t_text *text);
void			add_menu_light_cube(t_data *data,
					    t_text *text);
unsigned int		end_ray(t_eko *, t_thd *,
				const t_vec *);
t_vec			diff(const t_vec *, const t_vec *);
void			blur(t_bunny_pixelarray *arr,
			     unsigned int *tab,
			     unsigned int *limits);
void			blin_plan(t_vec *new, const t_vec *ray, t_eko *ret);
void			blin_cyl(t_vec *new, const t_vec *ray, t_eko *ret);
void			blin_cube(t_vec *new, const t_vec *ray, t_eko *ret);
void			blin_sphere(t_vec *new, const t_vec *ray, t_eko *ret);
void			hamon_cyl(t_vec *, const t_vec *, t_eko *);
void			hamon_cube(t_vec *, const t_vec *, t_eko *);
void			hamon_cone(t_vec *, const t_vec *, t_eko *);
void			hamon_sphere(t_vec *, const t_vec *, t_eko *);
void			hamon_plan(t_vec *, const t_vec *, t_eko *);
unsigned int		mid(t_color *, t_color *, double);
void			apply_remix(t_eko *, t_thd *, const t_vec *);
void			apply_alpha(t_eko *, t_thd *, const t_vec *);
void			mehdi(t_vec **vec, t_fig *elem,
			      t_color *col, const t_fig *fig);
void			bentor_white(t_bunny_pixelarray *pix);
int			fill_plane(t_fig *new, t_bunny_ini_scope *);
void			fill_cylindre(t_fig *new, t_bunny_ini_scope *);
void			nbr_setter(int *, long long *, int *);
void			apply_blur(t_bunny_pixelarray *,
				   unsigned int *);
int			cl_btw(int xmin, int xmax, int ymin, int ymax);
t_vec			cross_product(t_vec *one, t_vec *two);
void			start_edit(t_data *data, int mode, void *edit);
void			bentor_white(t_bunny_pixelarray *pix);
void			strcopy(char *one, char *two);
void			calc_dists(t_data *data);
void			rot_eye(t_eye *eye);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    t_data *data);
void			smart_cast(t_bunny_event_state state,
				   t_bunny_keysym sym,
				   t_data *data);
void			clear(t_bunny_pixelarray *pix, unsigned int color);
void			raytra_render_on(t_data *data);
void			check_line_blit(t_data *data);
int			raytra_setup_threads(t_data *data);
void			setup_t_thd(t_data *data, int i);
void			raytra_passive_mode(t_data *data);
int			load_scene(t_data *data);
int			my_strcmp_start(const char *one, const char *two);
int			putst_err(int fd, char *str, int ret);
int			len(const char *str);
t_bunny_response	raytra_loop(t_data *data);
char			*inttostr(int nb);
char			*stradd(char *one, char *two);
void			menu_menu_check(t_bunny_event_state state,
					t_bunny_mouse_button butt,
					t_data *data);
void			menu_menu_check_end(t_bunny_event_state state,
					    t_bunny_mouse_button butt,
					    t_data *data);
void			menu_check(t_bunny_event_state state,
				   t_bunny_mouse_button butt,
				   t_data *data);
void			save_plane_end(t_bunny_ini *ini,
				       t_fig *fig, char *indexer);
void			save_cube(t_bunny_ini *ini, t_fig *fig, int idx);
void			save_sphere(t_bunny_ini *ini, t_fig *fig, int idx);
void			save_eye(t_bunny_ini *ini, t_eye *eye);
void			save_lights(t_bunny_ini *ini, t_fig *lights);
void			save_cone(t_bunny_ini *ini, t_fig *fig, int idx);
void			save_cone_end(t_bunny_ini *ini, t_fig *fig, char *indexer);
void			save_cylindre(t_bunny_ini *ini, t_fig *fig, int idx);
void			save_cylindre_end(t_bunny_ini *ini, t_fig *fig, char *indexer);
void			save_plane(t_bunny_ini *ini, t_fig *fig, int idx);
void			menu_menu_check_render_end(t_bunny_event_state state,
				   t_bunny_mouse_button butt,
				   t_data *data);
void			save_file(t_data *data);
void			save_png(t_data *data, t_bunny_pixelarray *pix, int i,
				 t_bunny_position *pos);
void			save_ini(t_data *data, char *file);
void			save_objs(t_bunny_ini *ini, t_fig *fig);
void			menu_eye_edits_end(t_bunny_event_state state,
					   t_bunny_mouse_button butt,
					   t_data *data);
void			menu_obj_focus(t_bunny_event_state state,
				       t_bunny_mouse_button butt,
				       t_data *data);
void			check_idx_obj(t_data *data, int y);
void			menu_render_butt(t_bunny_event_state state,
					 t_bunny_mouse_button butt,
					 t_data *data);
void	menu_menu_check_render(t_bunny_event_state state,
			       t_bunny_mouse_button butt,
			       t_data *data);
void	menu_cub_mid(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_sph_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_sph_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_sph_mid(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_eye_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_con_mid(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_cyl_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_cyl_alone(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_cyl_last(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data);
void	menu_cyl_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_plan_two(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data);
void	menu_plan_one(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data);
void	menu_con_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_con_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_con_mid_end(t_bunny_event_state state,
			 t_bunny_mouse_button butt,
			 t_data *data);
void	menu_cyl_mid(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_lit_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_lit_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_cub_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_cub_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_plan_edits(t_bunny_event_state state,
			t_bunny_mouse_button butt,
			t_data *data);
void	menu_plan_six(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data);
void	menu_plan_five(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_plan_four(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	menu_plan_three(t_bunny_event_state state,
			t_bunny_mouse_button butt,
			t_data *data);
void	delete_fig(t_data *data, t_fig *fig);
void	delete_fig_end(t_data *data, t_fig *fig, t_fig *old, t_fig *tmp);
void	delete_this(t_fig *targ, t_fig *old, t_data *data, int mode);
void	delete_this_light(t_fig *targ, t_fig *old, t_data *data);
void	delete_this_fig(t_fig *targ, t_fig *old, t_data *data);
void	menu_add_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data);
void	menu_no_select(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
void	create_empty_elem(t_data *data);
void	create_empty_end(t_fig *tmp, t_data *data, t_fig *new);
void	menu_delete_edits(t_bunny_event_state state,
			  t_bunny_mouse_button butt,
			  t_data *data);
void	dists_init(t_data *data);
t_bunny_response	text(uint32_t unicode,
			     t_data *data);
void			text_end(uint32_t unicode,
				 t_data *data);
t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mouse_button butt,
			      t_data *data);
void	menu_add_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data);
int	functions_setup(t_data *data, int argc);
void	main_settup(t_data *data, char **argv);
void	main_settup_next(t_data *data);
int	start_checks(t_data *data);
int	end_checks(t_data *data);
void	apply_blur(t_bunny_pixelarray *arr,
			   unsigned int *tab);
void			menu_menu_check_render(t_bunny_event_state state,
					       t_bunny_mouse_button butt,
					       t_data *data);

/***************
** CREDITS TO **
****************
*/
void			rotaru(t_vec *, t_fig *);
unsigned int		alif(t_bunny_position *, t_thd *, t_vec *);
void			brunet(t_bunny_pixelarray *, unsigned int *, int *);
t_eko			bentor(const t_vec *, const t_eye *, const t_fig *);

#endif /* RT_H_ */
