/*
ShaderGlass preset interpolation / bilinear-adjustable imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/6f921ee4815a7894a33855974285b04545a4fa42/interpolation/bilinear-adjustable.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class InterpolationBilinearAdjustablePresetDef : public PresetDef
{
public:
	InterpolationBilinearAdjustablePresetDef() : PresetDef{}
	{
		Name = "bilinear-adjustable";
		Category = "interpolation";
	}

	virtual void Build() {
         	ShaderDefs.push_back(InterpolationShadersBilinearAdjustableShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "viewport"));
	}
};
}
