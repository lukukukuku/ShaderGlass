/*
ShaderGlass preset scalehq / 2xScaleHQ imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/6f921ee4815a7894a33855974285b04545a4fa42/scalehq/2xScaleHQ.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class Scalehq2xScaleHQPresetDef : public PresetDef
{
public:
	Scalehq2xScaleHQPresetDef() : PresetDef{}
	{
		Name = "2xScaleHQ";
		Category = "scalehq";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ScalehqShaders2xScaleHQShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "source")
.Param("scale_x", "2.0")
.Param("scale_y", "2.0"));
         	ShaderDefs.push_back(CubicShadersBicubicXShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source"));
         	ShaderDefs.push_back(CubicShadersBicubicYShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "viewport"));
	}
};
}
