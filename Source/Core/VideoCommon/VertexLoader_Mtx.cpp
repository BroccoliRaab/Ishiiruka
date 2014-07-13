// Copyright 2013 Dolphin Emulator Project
// Licensed under GPLv2
// Refer to the license.txt file included.
// Added for Ishiiruka by Tino
#include "VideoCommon/VertexLoader_Mtx.h"

void LOADERDECL Vertexloader_Mtx::PosMtx_ReadDirect_UByte()
{
	g_PipelineState.curposmtx = g_PipelineState.Read<u8>() & 0x3f;
}

void LOADERDECL Vertexloader_Mtx::PosMtx_Write()
{
	g_PipelineState.Write<u8>(g_PipelineState.curposmtx);
	g_PipelineState.Write<u8>(0);
	g_PipelineState.Write<u8>(0);
	g_PipelineState.Write<u8>(0);
}

void LOADERDECL Vertexloader_Mtx::PosMtxDisabled_Write()
{
	g_PipelineState.Write<u32>(0);
}

void LOADERDECL Vertexloader_Mtx::TexMtx_ReadDirect_UByte()
{
	g_PipelineState.curtexmtx[g_PipelineState.texmtxread] = g_PipelineState.Read<u8>() & 0x3f;
	g_PipelineState.texmtxread++;
}

void LOADERDECL Vertexloader_Mtx::TexMtx_Write_Float()
{
	g_PipelineState.Write(float(g_PipelineState.curtexmtx[g_PipelineState.texmtxwrite++]));
}

void LOADERDECL Vertexloader_Mtx::TexMtx_Write_Float2()
{
	g_PipelineState.Write(0.f);
	g_PipelineState.Write(float(g_PipelineState.curtexmtx[g_PipelineState.texmtxwrite++]));
}

void LOADERDECL Vertexloader_Mtx::TexMtx_Write_Float4()
{
	g_PipelineState.Write(0.f);
	g_PipelineState.Write(0.f);
	g_PipelineState.Write(float(g_PipelineState.curtexmtx[g_PipelineState.texmtxwrite++]));
	// Just to fill out with 0.
	g_PipelineState.Write(0.f);
}