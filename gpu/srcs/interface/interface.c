/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 20:47:59 by aanzieu           #+#    #+#             */
/*   Updated: 2017/09/11 17:17:39 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NK_INCLUDE_MEDIA
#define NK_INCLUDE_FONT_BAKING
#include "../../includes/rt.h"
#include "header/nuklear.h"
#include "header/gui.h"

void
die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
}
/* glfw callbacks (I don't know if there is a easier way to access text and scroll )*/
void error_callback(int e, const char *d)
{
	printf("Error %d: %s\n", e, d);
}

void text_input(GLFWwindow *win, unsigned int codepoint)
{
	nk_input_unicode((struct nk_context*)
	glfwGetWindowUserPointer(win), codepoint);
}

void scroll_input(GLFWwindow *win, double _, double yoff)
{
	UNUSED(_);nk_input_scroll((struct nk_context*)
	glfwGetWindowUserPointer(win), nk_vec2(0, (float)yoff));
}

void    gui_calls(struct file_browser *browser, struct nk_context *ctx, struct media *media, t_world *world)
{
	(void)browser;

	if (world->a_h != NULL)
	{
		scene_topbar(ctx, media, world);
		scene_parameters(ctx, media, world);
		camera_control_bar(ctx, media, world);
		render_scene(ctx, media, world->a_h, world);
		objects_param(ctx, media, world);
		//file_browser_run(browser, ctx);
	}
	else
	{
		scene_topbar(ctx, media, world);
		objects_param(ctx, media, world);
		//file_browser_run(browser, ctx);
	}
}
