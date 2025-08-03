#include "CappuPCH.h"
#include "RenderCommands.h"

#include "Platforms/API/OpenGL/GLRendererAPI.h"

Cappu::RendererAPI* Cappu::RenderCommand::s_rendererAPI = new GLRendererAPI;