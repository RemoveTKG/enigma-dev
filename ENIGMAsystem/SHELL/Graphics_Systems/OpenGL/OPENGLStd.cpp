/*********************************************************************************\
**                                                                              **
**  Copyright (C) 2008 Josh Ventura                                             **
**                                                                              **
**  This file is a part of the ENIGMA Development Environment.                  **
**                                                                              **
**                                                                              **
**  ENIGMA is free software: you can redistribute it and/or modify it under the **
**  terms of the GNU General Public License as published by the Free Software   **
**  Foundation, version 3 of the license or any later version.                  **
**                                                                              **
**  This application and its source code is distributed AS-IS, WITHOUT ANY      **
**  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS   **
**  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more       **
**  details.                                                                    **
**                                                                              **
**  You should have recieved a copy of the GNU General Public License along     **
**  with this code. If not, see <http://www.gnu.org/licenses/>                  **
**                                                                              **
**  ENIGMA is an environment designed to create games and other programs with a **
**  high-level, fully compilable language. Developers of ENIGMA or anything     **
**  associated with ENIGMA are in no way responsible for its users or           **
**  applications created by its users, or damages caused by the environment     **
**  or programs made in the environment.                                        **
**                                                                              **
\*********************************************************************************/
/*
#ifdef CODEBLOX
#  include <GL/glee.h>
#else
#  include <../additional/glee/GLee.h>
#endif*/
#include <GL/gl.h>

namespace enigma
{
  unsigned cur_bou_tha_noo_sho_eve_cha_eve=0;
  float currentcolor[4]={0,0,0,1};
  bool glew_isgo;
  bool pbo_isgo;
}

#include "../../Universal_System/roomsystem.h"

void graphicssystem_initialize()
{
	#if GMSURFACE
	glBindFramebufferEXT   =    (PFNGLBINDFRAMEBUFFEREXTPROC) wglGetProcAddress("glBindFramebufferEXT");
	glGenFramebuffersEXT   =    (PFNGLGENFRAMEBUFFERSEXTPROC) wglGetProcAddress("glGenFramebuffersEXT");
	glFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) wglGetProcAddress("glFramebufferTexture2DEXT");
	if (!(glBindFramebufferEXT&&glGenFramebuffersEXT&&glFramebufferTexture2DEXT))
		MessageBox(0,"Additional drawing surfaces cannot be created. Extension unsupported by graphics card","Error",MB_OK);
	#endif
	//enigma::pbo_isgo=GL_ARB_pixel_buffer_object;
	glMatrixMode(GL_PROJECTION);
	glClearColor(1,1,1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLoadIdentity();
	glViewport(0,0,(int)room_width,(int)room_height);
	glOrtho(0,(int)room_width-1,(int)room_height-1,0,-1,1);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_TEXTURE_2D);
	glAlphaFunc(GL_ALWAYS,0);
	glColor4f(0,0,0,1);
}
