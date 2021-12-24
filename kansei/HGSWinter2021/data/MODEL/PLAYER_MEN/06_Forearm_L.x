xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 90;
 0.00000;16.39500;-2.26000;,
 0.63672;16.39500;-2.16845;,
 0.63672;-0.19500;-2.16845;,
 0.00000;-0.19500;-2.26000;,
 1.22185;16.39500;-1.90123;,
 1.22185;-0.19500;-1.90123;,
 1.70799;16.39500;-1.47999;,
 1.70799;-0.19500;-1.47999;,
 2.05577;16.39500;-0.93884;,
 2.05577;-0.19500;-0.93884;,
 2.23700;16.39500;-0.32163;,
 2.23700;-0.19500;-0.32163;,
 2.23700;16.39500;0.32163;,
 2.23700;-0.19500;0.32163;,
 2.05577;16.39500;0.93884;,
 2.05577;-0.19500;0.93884;,
 1.70799;16.39500;1.47999;,
 1.70799;-0.19500;1.47999;,
 1.22185;16.39500;1.90123;,
 1.22185;-0.19500;1.90123;,
 0.63672;16.39500;2.16845;,
 0.63672;-0.19500;2.16845;,
 0.00000;16.39500;2.26000;,
 0.00000;-0.19500;2.26000;,
 -0.63672;16.39500;2.16845;,
 -0.63672;-0.19500;2.16845;,
 -1.22185;16.39500;1.90123;,
 -1.22185;-0.19500;1.90123;,
 -1.70799;16.39500;1.47999;,
 -1.70799;-0.19500;1.47999;,
 -2.05577;16.39500;0.93884;,
 -2.05577;-0.19500;0.93884;,
 -2.23700;16.39500;0.32163;,
 -2.23700;-0.19500;0.32163;,
 -2.23700;16.39500;-0.32163;,
 -2.23700;-0.19500;-0.32163;,
 -2.05577;16.39500;-0.93884;,
 -2.05577;-0.19500;-0.93884;,
 -1.70800;16.39500;-1.47998;,
 -1.70800;-0.19500;-1.47998;,
 -1.22185;16.39500;-1.90123;,
 -1.22185;-0.19500;-1.90123;,
 -0.63672;16.39500;-2.16845;,
 -0.63672;-0.19500;-2.16845;,
 0.00000;16.39500;-2.26000;,
 0.00000;-0.19500;-2.26000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;16.39500;0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;,
 0.00000;-0.19500;-0.00000;;
 
 66;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 3;46,1,0;,
 3;47,4,1;,
 3;48,6,4;,
 3;49,8,6;,
 3;50,10,8;,
 3;51,12,10;,
 3;52,14,12;,
 3;53,16,14;,
 3;54,18,16;,
 3;55,20,18;,
 3;56,22,20;,
 3;57,24,22;,
 3;58,26,24;,
 3;59,28,26;,
 3;60,30,28;,
 3;61,32,30;,
 3;62,34,32;,
 3;63,36,34;,
 3;64,38,36;,
 3;65,40,38;,
 3;66,42,40;,
 3;67,44,42;,
 3;68,3,2;,
 3;69,2,5;,
 3;70,5,7;,
 3;71,7,9;,
 3;72,9,11;,
 3;73,11,13;,
 3;74,13,15;,
 3;75,15,17;,
 3;76,17,19;,
 3;77,19,21;,
 3;78,21,23;,
 3;79,23,25;,
 3;80,25,27;,
 3;81,27,29;,
 3;82,29,31;,
 3;83,31,33;,
 3;84,33,35;,
 3;85,35,37;,
 3;86,37,39;,
 3;87,39,41;,
 3;88,41,43;,
 3;89,43,45;;
 
 MeshMaterialList {
  3;
  66;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.890000;0.701320;0.443220;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.250000;0.197000;0.124500;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.088000;0.088000;0.088000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\player_cloth00.jpg";
   }
  }
 }
 MeshNormals {
  24;
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.281735;0.000000;-0.959492;,
  0.540639;0.000000;-0.841254;,
  0.755747;0.000000;-0.654864;,
  0.909631;0.000000;-0.415418;,
  0.989821;0.000000;-0.142316;,
  0.989821;0.000000;0.142316;,
  0.909631;0.000000;0.415418;,
  0.755747;0.000000;0.654864;,
  0.540639;0.000000;0.841254;,
  0.281735;0.000000;0.959492;,
  0.000000;0.000000;1.000000;,
  -0.281735;0.000000;0.959492;,
  -0.540639;0.000000;0.841254;,
  -0.755747;0.000000;0.654864;,
  -0.909631;0.000000;0.415418;,
  -0.989821;0.000000;0.142316;,
  -0.989821;0.000000;-0.142316;,
  -0.909632;0.000000;-0.415416;,
  -0.755749;0.000000;-0.654862;,
  -0.540640;0.000000;-0.841254;,
  -0.281735;0.000000;-0.959492;,
  0.000000;-1.000000;-0.000000;;
  66;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;22,1,1,22;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;;
 }
 MeshTextureCoords {
  90;
  0.000000;0.000000;,
  0.045450;0.000000;,
  0.045450;1.000000;,
  0.000000;1.000000;,
  0.090910;0.000000;,
  0.090910;1.000000;,
  0.136360;0.000000;,
  0.136360;1.000000;,
  0.181820;0.000000;,
  0.181820;1.000000;,
  0.227270;0.000000;,
  0.227270;1.000000;,
  0.272730;0.000000;,
  0.272730;1.000000;,
  0.318180;0.000000;,
  0.318180;1.000000;,
  0.363640;0.000000;,
  0.363640;1.000000;,
  0.409090;0.000000;,
  0.409090;1.000000;,
  0.454550;0.000000;,
  0.454550;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.545450;0.000000;,
  0.545450;1.000000;,
  0.590910;0.000000;,
  0.590910;1.000000;,
  0.636360;0.000000;,
  0.636360;1.000000;,
  0.681820;0.000000;,
  0.681820;1.000000;,
  0.727270;0.000000;,
  0.727270;1.000000;,
  0.772730;0.000000;,
  0.772730;1.000000;,
  0.818180;0.000000;,
  0.818180;1.000000;,
  0.863640;0.000000;,
  0.863640;1.000000;,
  0.909090;0.000000;,
  0.909090;1.000000;,
  0.954550;0.000000;,
  0.954550;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.022730;0.000000;,
  0.068180;0.000000;,
  0.113640;0.000000;,
  0.159090;0.000000;,
  0.204550;0.000000;,
  0.250000;0.000000;,
  0.295450;0.000000;,
  0.340910;0.000000;,
  0.386360;0.000000;,
  0.431820;0.000000;,
  0.477270;0.000000;,
  0.522730;0.000000;,
  0.568180;0.000000;,
  0.613640;0.000000;,
  0.659090;0.000000;,
  0.704550;0.000000;,
  0.750000;0.000000;,
  0.795450;0.000000;,
  0.840910;0.000000;,
  0.886360;0.000000;,
  0.931820;0.000000;,
  0.977270;0.000000;,
  0.022730;1.000000;,
  0.068180;1.000000;,
  0.113640;1.000000;,
  0.159090;1.000000;,
  0.204550;1.000000;,
  0.250000;1.000000;,
  0.295450;1.000000;,
  0.340910;1.000000;,
  0.386360;1.000000;,
  0.431820;1.000000;,
  0.477270;1.000000;,
  0.522730;1.000000;,
  0.568180;1.000000;,
  0.613640;1.000000;,
  0.659090;1.000000;,
  0.704550;1.000000;,
  0.750000;1.000000;,
  0.795450;1.000000;,
  0.840910;1.000000;,
  0.886360;1.000000;,
  0.931820;1.000000;,
  0.977270;1.000000;;
 }
}