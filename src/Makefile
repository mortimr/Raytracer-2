##
## Makefile for minishell2 in /home/rotaru_i/Coding/PSU/minishell_reborn
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Mon Mar 14 22:16:05 2016 Iulian Rotaru
## Last update Sun May 22 21:07:55 2016 
##

CC		= 	gcc

CPPFLAGS	+=	-I../inc				\
		   	-I/home/${USER}/.froot/include

LDLIB		+=	-lcarrot				\
	   		-llapin -lsfml-audio -lsfml-graphics	\
	   		-lsfml-window -lsfml-system -lstdc++	\
	   		-ldl -lm 				\
	   		-lX11					\
	   		-lpthread				\

LDFLAGS		+= 	-L./cpp					\
	   		-L/home/${USER}/.froot/lib     		\

CFLAGS		+=	-D_REENTRANT				\
	   		-O2					\
	   		-Wall -Wextra #-Werror

RM		= 	rm -f

NAME		= 	raytracer2

SRCS		= 	main/main.c 				\
			main/strcopy.c				\
			main/clear.c				\
			main/raytra_loop.c			\
			main/len_and_stuff.c			\
			main/menu_check.c			\
			main/save_lights.c			\
			main/save_plne.c			\
			main/save_objs.c			\
			main/menu_ch_rend.c			\
			main/menu_con.c				\
			main/menu_cub_end.c			\
			main/menu_cyl_end.c			\
			main/menu_eye_e.c			\
			main/menu_plan_three.c			\
			main/delete_this_fig.c			\
			main/menu_del_edits.c			\
			main/menu_add.c				\
			main/end_checks.c			\
	  		fig_hub.c 				\
			sphere.c 				\
			my_getnbr.c 				\
			raytracing/alpha.c			\
			place_new.c 				\
			raytracing/apply_things.c 		\
			plane.c 				\
			misc.c 					\
			raytracing/reflects.c			\
			cone.c 					\
			cube.c 					\
			raytracing/bentor.c			\
			light.c 				\
			getnbr_utils.c				\
			menu/main_menu.c 			\
			menu/the_pixfill.c 			\
			menu/menu_blur.c 			\
			menu/render_left.c 			\
			menu/render_down.c 			\
			menu/menu_render.c 			\
			menu/menu_menu.c 			\
			menu/menu_threads.c 			\
			menu/get_pix_end.c 			\
			menu/aff_eye_dir.c 			\
			menu/aff_alpha.c 			\
			menu/aff_cube_pos.c 			\
			menu/aff_cube_size.c 			\
			menu/aff_light.c 			\
			menu/aff_cyl_sh.c 			\
			menu/aff_cylindre.c 			\
			menu/aff_cone_angle.c 			\
			menu/aff_plane_pos.c 			\
			menu/aff_plane_min.c 			\
			menu/aff_plane.c 			\
			menu/add_menu.c 			\
			blur/blur.c				\
			blur/blur_end.c				\
			eye.c 					\
			color_mixer.c 				\
		  	cylindre.c 				\
			fill_cylindre.c				\
			raytracing/replane.c			\
			raytracing/raytracing.c 		\
			my_blitstr.c 				\
			my_blitstr_end.c 			\
			my_bunny_blit.c				\
			raytracing/utils_ray.c			\
			raytracing/plane_sphere.c		\
			raytracing/cube_cone.c			\
			raytracing/base_forms.c			\
			raytracing/rotaru.c			\
			raytracing/lights.c			\
			raytracing/alif.c			\
			raytracing/send_ray.c			\
			raytracing/rays_details.c		\

OBJ		= 	$(SRCS:.c=.o)

PROJ		= 	-RTV2-

REDDARK		=	\033[31;2m

RED		= 	\033[31;1m

GREEN		= 	\033[32;1m

YEL		= 	\033[33;1m

BLUE		= 	\033[34;1m

PINK		= 	\033[35;1m

CYAN		= 	\033[36;1m

RES		= 	\033[0m

all: 		$(NAME)

$(NAME):	 $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB)
	@cp $(NAME) ..
	@printf "\n$(BLUE)•••••••••••••••••••••••••••••••••••••••••••••$(RES)\n"
	@printf "$(BLUE)••► $(GREEN)Compilation done for $(CYAN)$(NAME)$(GREEN) ! $(YEL)[$(GREEN)✓$(YEL)]$(BLUE) ◂••$(RES)\n"
	@printf "$(BLUE)•••••••••••••••••••••••••••••••••••••••••••••$(RES)\n"
	@echo "$(BLUE)"
	@echo " ██████╗  █████╗ ██╗   ██╗████████╗██████╗  █████╗  ██████╗███████╗██████╗     ██████╗"
	@echo " ██╔══██╗██╔══██╗╚██╗ ██╔╝╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗    ╚════██╗"
	@echo " ██████╔╝███████║ ╚████╔╝    ██║   ██████╔╝███████║██║     █████╗  ██████╔╝     █████╔╝"
	@echo " ██╔══██╗██╔══██║  ╚██╔╝     ██║   ██╔══██╗██╔══██║██║     ██╔══╝  ██╔══██╗    ██╔═══╝"
	@echo " ██║  ██║██║  ██║   ██║      ██║   ██║  ██║██║  ██║╚██████╗███████╗██║  ██║    ███████╗"
	@echo " ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚═╝  ╚═╝    ╚══════╝"
	@echo "\033[0m"
	@cp $(NAME) ..
	@if [ -e .signa ]; then cat .signa; fi

clean:
	@$(foreach var, $(OBJ), if [ -e $(var) ] ; then \
	printf "$(RED) ✗ $(YEL)[$(BLUE)$(PROJ)$(YEL)] •• $(GREEN)$(notdir $(var))$(RES) $(YEL): \t[$(BLUE)RM$(YEL)]$(RES)\n" \
	&& $(RM) $(var) ; fi ;)

fclean: 	clean
	@if [ -e $(NAME) ] ; then \
	printf "$(RED) ✗ $(YEL)[$(BLUE)$(PROJ)$(YEL)] •• $(GREEN)$(notdir $(NAME))$(RES) $(YEL): \t[$(BLUE)RM$(YEL)]$(RES)\n" \
	&& $(RM) $(NAME) && $(RM) ../$(NAME); fi ;


re: 	fclean all

%.o: 		%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIB) && \
	printf "$(YEL) ► [$(BLUE)$(PROJ)$(YEL)] •• $(RED)$(dir $<)$(GREEN)$(notdir $<)$(RES) $(YEL): \t[$(GREEN)✓✓$(YEL)]$(RES)\n" || printf "$(YEL) ► [$(BLUE)$(PROJ)$(YEL)] •• $(RED)$(dir $<)$(GREEN)$(notdir $<)$(RES) $(YEL): \t[$(RED)✗$(YEL)]$(RES)\n"

.PHONY: all clean fclean re
