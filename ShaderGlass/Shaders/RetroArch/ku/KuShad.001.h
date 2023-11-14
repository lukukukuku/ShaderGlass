{
    "id" : 6821, "name" : "New Composed Shader",
                          "fragment"
        : "#define GLSLIFY 1\n\nprecision highp float;\nprecision highp int;\nuniform float time;\nuniform vec2 resolution;\nuniform sampler2D bgTexture;\nuniform sampler2D "
          "texture;\nuniform float glitchInterval;\nuniform float glitchRate;\nvarying vec2 vUv;\nfloat random(vec2 c) \n{\n    return fract(sin(dot(c.xy, vec2(12.9898, 78.233))) "
          "* 43758.5453);\n}\nvec3 mod289(vec3 x) \n{\n    return x - floor(x * (1.0 / 289.0)) * 289.0;\n}\nvec4 mod289(vec4 x) \n{\n    return x - floor(x * (1.0 / 289.0)) * "
          "289.0;\n}\nvec4 permute(vec4 x) \n{\n    return mod289(((x * 34.0) + 1.0) * x);\n}\nvec4 taylorInvSqrt(vec4 r) \n{\n    return 1.79284291400159 - 0.85373472095314 * "
          "r;\n}\nfloat snoise(vec3 v) \n{\n    const vec2 C = vec2(1.0 / 6.0, 1.0 / 3.0);\n    const vec4 D = vec4(0.0, 0.5, 1.0, 2.0);\n    vec3 i = floor(v + dot(v, C.yyy));\n "
          "   vec3 x0 = v - i + dot(i, C.xxx);\n    vec3 g_0 = step(x0.yzx, x0.xyz);\n    vec3 l = 1.0 - g_0;\n    vec3 i1 = min(g_0.xyz, l.zxy);\n    vec3 i2 = max(g_0.xyz, "
          "l.zxy);\n    vec3 x1 = x0 - i1 + C.xxx;\n    vec3 x2 = x0 - i2 + C.yyy;\n    vec3 x3 = x0 - D.yyy;\n    i = mod289(i);\n    vec4 p = permute(permute(permute(i.z + "
          "vec4(0.0, i1.z, i2.z, 1.0)) + i.y + vec4(0.0, i1.y, i2.y, 1.0)) + i.x + vec4(0.0, i1.x, i2.x, 1.0));\n    float n_ = 0.142857142857;\n    vec3 ns = n_ * D.wyz - "
          "D.xzx;\n    vec4 j = p - 49.0 * floor(p * ns.z * ns.z);\n    vec4 x_ = floor(j * ns.z);\n    vec4 y_ = floor(j - 7.0 * x_);\n    vec4 x = x_ * ns.x + ns.yyyy;\n    "
          "vec4 y = y_ * ns.x + ns.yyyy;\n    vec4 h = 1.0 - abs(x) - abs(y);\n    vec4 b0 = vec4(x.xy, y.xy);\n    vec4 b1 = vec4(x.zw, y.zw);\n    vec4 s0 = floor(b0) * 2.0 + "
          "1.0;\n    vec4 s1 = floor(b1) * 2.0 + 1.0;\n    vec4 sh = -step(h, vec4(0.0));\n    vec4 a0 = b0.xzyw + s0.xzyw * sh.xxyy;\n    vec4 a1 = b1.xzyw + s1.xzyw * "
          "sh.zzww;\n    vec3 p0 = vec3(a0.xy, h.x);\n    vec3 p1 = vec3(a0.zw, h.y);\n    vec3 p2 = vec3(a1.xy, h.z);\n    vec3 p3 = vec3(a1.zw, h.w);\n    vec4 norm = "
          "taylorInvSqrt(vec4(dot(p0, p0), dot(p1, p1), dot(p2, p2), dot(p3, p3)));\n    p0 *= norm.x;\n    p1 *= norm.y;\n    p2 *= norm.z;\n    p3 *= norm.w;\n    vec4 m = "
          "max(0.6 - vec4(dot(x0, x0), dot(x1, x1), dot(x2, x2), dot(x3, x3)), 0.0);\n    m = m * m;\n    return 42.0 * dot(m * m, vec4(dot(p0, x0), dot(p1, x1), dot(p2, x2), "
          "dot(p3, x3)));\n}\nvec4 Glitch_Shader1695174848509_358_main(void) \n{\n    vec4 Glitch_Shader1695174848509_358_gl_FragColor = vec4(0.0);\n    float strength = "
          "smoothstep(glitchInterval * glitchRate, glitchInterval, glitchInterval - mod(time, glitchInterval));\n    vec2 shake = vec2(strength * 8.0 + 0.5) * "
          "vec2(random(vec2(time)) * 2.0 - 1.0, random(vec2(time * 2.0)) * 2.0 - 1.0) / resolution;\n    float y = vUv.y * resolution.y;\n    float rgbWave = (snoise(vec3(0.0, y "
          "* 0.01, time * 400.0)) * (2.0 + strength * 32.0) * snoise(vec3(0.0, y * 0.02, time * 200.0)) * (1.0 + strength * 4.0) + step(0.9995, sin(y * 0.005 + time * 1.6)) * "
          "12.0 + step(0.9999, sin(y * 0.005 + time * 2.0)) * -18.0) / resolution.x;\n    float rgbDiff = (6.0 + sin(time * 500.0 + vUv.y * 40.0) * (20.0 * strength + 1.0)) / "
          "resolution.x;\n    float rgbUvX = vUv.x + rgbWave;\n    float r = texture2D(texture, vec2(rgbUvX + rgbDiff, vUv.y) + shake).r;\n    float g = texture2D(texture, "
          "vec2(rgbUvX, vUv.y) + shake).g;\n    float b = texture2D(texture, vec2(rgbUvX - rgbDiff, vUv.y) + shake).b;\n    float whiteNoise = (random(vUv + mod(time, 10.0)) * "
          "2.0 - 1.0) * (0.15 + strength * 0.15);\n    float bnTime = floor(time * 20.0) * 200.0;\n    float noiseX = step((snoise(vec3(0.0, vUv.x * 3.0, bnTime)) + 1.0) / 2.0, "
          "0.12 + strength * 0.3);\n    float noiseY = step((snoise(vec3(0.0, vUv.y * 3.0, bnTime)) + 1.0) / 2.0, 0.12 + strength * 0.3);\n    float bnMask = noiseX * noiseY;\n   "
          " float bnUvX = vUv.x + sin(bnTime) * 0.2 + rgbWave;\n    float bnR = texture2D(texture, vec2(bnUvX + rgbDiff, vUv.y)).r * bnMask;\n    float bnG = texture2D(texture, "
          "vec2(bnUvX, vUv.y)).g * bnMask;\n    float bnB = texture2D(texture, vec2(bnUvX - rgbDiff, vUv.y)).b * bnMask;\n    vec4 blockNoise = vec4(bnR, bnG, bnB, 1.0);\n    "
          "float bnTime2 = floor(time * 25.0) * 300.0;\n    float noiseX2 = step((snoise(vec3(0.0, vUv.x * 2.0, bnTime2)) + 1.0) / 2.0, 0.12 + strength * 0.5);\n    float noiseY2 "
          "= step((snoise(vec3(0.0, vUv.y * 8.0, bnTime2)) + 1.0) / 2.0, 0.12 + strength * 0.3);\n    float bnMask2 = noiseX2 * noiseY2;\n    float bnR2 = texture2D(texture, "
          "vec2(bnUvX + rgbDiff, vUv.y)).r * bnMask2;\n    float bnG2 = texture2D(texture, vec2(bnUvX, vUv.y)).g * bnMask2;\n    float bnB2 = texture2D(texture, vec2(bnUvX - "
          "rgbDiff, vUv.y)).b * bnMask2;\n    vec4 blockNoise2 = vec4(bnR2, bnG2, bnB2, 1.0);\n    float waveNoise = (sin(vUv.y * 1200.0) + 1.0) / 2.0 * (0.15 + strength * "
          "0.2);\n    vec4 vv = vec4(r, g, b, 1.0) * (1.0 - bnMask - bnMask2) + (whiteNoise + blockNoise + blockNoise2 - waveNoise);\n    vv.a = texture2D(texture, vec2(rgbUvX, "
          "vUv.y) + shake).a;\n    Glitch_Shader1695174848509_358_gl_FragColor = mix(texture2D(bgTexture, vUv).rgba, vv, vv.a);\n    Glitch_Shader1695174848509_358_gl_FragColor = "
          "vv;\n    return Glitch_Shader1695174848509_358_gl_FragColor *= 1.0;\n}\nvoid main() \n{\n    gl_FragColor = Glitch_Shader1695174848509_358_main();}\n",
          "vertex" : "precision highp float;\nprecision highp int;\nuniform mat4 modelMatrix;\nuniform mat4 modelViewMatrix;\nuniform mat4 projectionMatrix;\nuniform mat4 "
                     "viewMatrix;\nuniform mat3 normalMatrix;\nuniform vec3 cameraPosition;\nuniform float time;\nattribute vec3 position;\nattribute vec3 normal;\nattribute vec2 "
                     "uv;\nattribute vec2 uv2;\nvarying vec3 vPosition;\nvarying vec3 vNormal;\nvarying vec2 vUv;\nvarying vec2 vUv2;\nvec4 Glitch_Shader1695174848509_358_main() "
                     "\n{\n    vec4 Glitch_Shader1695174848509_358_gl_Position = vec4(0.0);\n    vNormal = normal;\n    vUv = uv;\n    vUv2 = uv2;\n    vPosition = position;\n    "
                     "Glitch_Shader1695174848509_358_gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);\n    return "
                     "Glitch_Shader1695174848509_358_gl_Position *= 1.0;\n}\nvoid main() \n{\n    gl_Position = Glitch_Shader1695174848509_358_main();}\n",
                     "uniforms" : {
                         "time" : {"type" : "f", "glslType" : "float"},
                         "resolution" : {"value" : {"x" : "640", "y" : "480"}, "type" : "v2", "glslType" : "vec2"},
                         "texture" : {"value" : null, "type" : "t", "glslType" : "sampler2D"},
                         "glitchInterval" : {"value" : "10.0", "type" : "f", "glslType" : "float"},
                         "glitchRate" : {"value" : "5.1", "type" : "f", "glslType" : "float"},
                         "bgTexture" : {"value" : null, "type" : "t", "glslType" : "sampler2D"},
                         "cameraPosition" : {"type" : "v3", "glslType" : "vec3"}
                     },
                                  "url" : "http://shaderfrog.com/app/view/6821",
                                          "user":
    {
        "username" : "hxy228", "url" : "http://shaderfrog.com/app/profile/andrewray"
    }
}