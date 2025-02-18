/*
ShaderGlass preset xsal / 2xsal-level2-crt imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/6f921ee4815a7894a33855974285b04545a4fa42/xsal/2xsal-level2-crt.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class Xsal2xsalLevel2CrtPresetDef : public PresetDef
{
public:
	Xsal2xsalLevel2CrtPresetDef() : PresetDef{}
	{
		Name = "2xsal-level2-crt";
		Category = "xsal";
	}

	virtual void Build() {
         	ShaderDefs.push_back(XsalShaders2xsalLevel2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "2.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(CrtShadersDotmaskShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "viewport"));
	}
};
}
