Shader "Custom/01_uv_animation" {
	Properties {
		_Color ("Color", Color) = (1,1,1,1)
		_MainTex ("Albedo (RGB)", 2D) = "white" {}
		_SizeX("col", Int) = 11
		_SizeY("row", Int) = 2
		_Speed("Speed", Float) = 150
	}
	SubShader {
		CGPROGRAM
		#pragma surface surf Lambert

		float4 _Color;
		sampler2D _MainTex;
		uniform int _SizeX;
		uniform int _SizeY;
		uniform float _Speed;

		struct Input{
			float2 uv_MainTex;
		};

		void surf(Input IN, inout SurfaceOutput o) {
			float2 curUV;
			float deltaX = 1.0 / _SizeX;
			float deltaY = 1.0 / _SizeY;
			int row = fmod(_Time * _Speed / _SizeX, _SizeY);
			int col = fmod(_Time * _Speed, _SizeX);
			curUV.x = IN.uv_MainTex.x / _SizeX + col * deltaX;
			curUV.y = IN.uv_MainTex.y / _SizeY + row * deltaY;
			float4 c = tex2D(_MainTex, curUV) * _Color;
			o.Albedo = c.rgb;
			o.Alpha = c.a;
		}
		ENDCG
	}
	FallBack "Diffuse"
}
