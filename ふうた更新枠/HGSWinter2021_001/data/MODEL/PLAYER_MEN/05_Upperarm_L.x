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
 -1.36769;-0.02983;-1.77660;,
 -0.79454;-0.04240;-2.12124;,
 -1.02957;-16.35043;-2.01516;,
 -1.60271;-16.33785;-1.67051;,
 -0.14752;-0.05488;-2.29043;,
 -0.38254;-16.36291;-2.18434;,
 0.52099;-0.06624;-2.27045;,
 0.28596;-16.37428;-2.16436;,
 1.15680;-0.07559;-2.06291;,
 0.92177;-16.38362;-1.95682;,
 1.70842;-0.08217;-1.68465;,
 1.47339;-16.39019;-1.57856;,
 2.13115;-0.08542;-1.16630;,
 1.89612;-16.39344;-1.06020;,
 2.39074;-0.08508;-0.54985;,
 2.15572;-16.39313;-0.44376;,
 2.46618;-0.08124;0.11475;,
 2.23115;-16.38927;0.22085;,
 2.35134;-0.07413;0.77367;,
 2.11631;-16.38216;0.87975;,
 2.05553;-0.06431;1.37351;,
 1.82050;-16.37237;1.47960;,
 1.60271;-0.05272;1.86569;,
 1.36768;-16.36074;1.97179;,
 1.02957;-0.04013;2.21034;,
 0.79454;-16.34817;2.31642;,
 0.38254;-0.02765;2.37952;,
 0.14751;-16.33569;2.48561;,
 -0.28596;-0.01627;2.35955;,
 -0.52099;-16.32432;2.46564;,
 -0.92178;-0.00695;2.15200;,
 -1.15680;-16.31497;2.25808;,
 -1.47340;-0.00038;1.77374;,
 -1.70842;-16.30840;1.87983;,
 -1.89613;0.00288;1.25539;,
 -2.13115;-16.30516;1.36148;,
 -2.15572;0.00257;0.63894;,
 -2.39075;-16.30548;0.74503;,
 -2.23115;-0.00129;-0.02566;,
 -2.46619;-16.30934;0.08044;,
 -2.11632;-0.00842;-0.68457;,
 -2.35134;-16.31647;-0.57849;,
 -1.82050;-0.01820;-1.28442;,
 -2.05553;-16.32623;-1.17834;,
 -1.36769;-0.02983;-1.77660;,
 -1.60271;-16.33785;-1.67051;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 0.11751;-0.04127;0.04454;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;,
 -0.11752;-16.34929;0.15063;;
 
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
  1;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\player_cloth00.jpg";
   }
  }
 }
 MeshNormals {
  68;
  0.017243;0.999821;-0.007784;,
  -0.631998;0.004067;-0.774959;,
  -0.388111;-0.000402;-0.921613;,
  -0.112781;-0.004838;-0.993608;,
  0.171699;-0.008883;-0.985109;,
  0.442261;-0.012208;-0.896803;,
  0.676993;-0.014544;-0.735846;,
  0.856888;-0.015701;-0.515264;,
  0.967356;-0.015587;-0.252940;,
  0.999453;-0.014210;0.029875;,
  0.950577;-0.011681;0.310268;,
  0.824694;-0.008206;0.565520;,
  0.631999;-0.004067;0.774958;,
  0.388109;0.000402;0.921614;,
  0.112788;0.004838;0.993607;,
  -0.171701;0.008883;0.985109;,
  -0.442267;0.012207;0.896801;,
  -0.676989;0.014543;0.735849;,
  -0.856887;0.015701;0.515264;,
  -0.967356;0.015587;0.252940;,
  -0.999453;0.014210;-0.029873;,
  -0.950577;0.011681;-0.310268;,
  -0.824692;0.008206;-0.565523;,
  -0.017242;-0.999821;0.007782;,
  0.017249;0.999821;-0.007785;,
  0.017240;0.999821;-0.007778;,
  0.017236;0.999821;-0.007784;,
  0.017232;0.999821;-0.007781;,
  0.017249;0.999821;-0.007776;,
  0.017247;0.999821;-0.007781;,
  0.017233;0.999821;-0.007797;,
  0.017237;0.999821;-0.007771;,
  0.017247;0.999821;-0.007758;,
  0.017259;0.999821;-0.007815;,
  0.017230;0.999821;-0.007792;,
  0.017231;0.999821;-0.007766;,
  0.017260;0.999821;-0.007795;,
  0.017249;0.999821;-0.007790;,
  0.017227;0.999821;-0.007795;,
  0.017222;0.999821;-0.007789;,
  0.017244;0.999821;-0.007778;,
  0.017249;0.999821;-0.007771;,
  0.017252;0.999821;-0.007765;,
  0.017253;0.999821;-0.007790;,
  0.017250;0.999821;-0.007804;,
  0.017239;0.999821;-0.007782;,
  -0.017240;-0.999821;0.007778;,
  -0.017254;-0.999821;0.007792;,
  -0.017243;-0.999821;0.007789;,
  -0.017233;-0.999821;0.007788;,
  -0.017239;-0.999821;0.007785;,
  -0.017242;-0.999821;0.007785;,
  -0.017244;-0.999821;0.007779;,
  -0.017250;-0.999821;0.007767;,
  -0.017251;-0.999821;0.007772;,
  -0.017256;-0.999821;0.007792;,
  -0.017247;-0.999821;0.007788;,
  -0.017242;-0.999821;0.007775;,
  -0.017251;-0.999821;0.007782;,
  -0.017243;-0.999821;0.007781;,
  -0.017239;-0.999821;0.007780;,
  -0.017243;-0.999821;0.007779;,
  -0.017234;-0.999821;0.007787;,
  -0.017230;-0.999821;0.007787;,
  -0.017237;-0.999821;0.007771;,
  -0.017240;-0.999821;0.007788;,
  -0.017234;-0.999821;0.007792;,
  -0.017224;-0.999821;0.007767;;
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
  3;0,24,25;,
  3;0,26,24;,
  3;0,27,26;,
  3;0,28,27;,
  3;0,29,28;,
  3;0,30,29;,
  3;0,31,30;,
  3;0,32,31;,
  3;0,33,32;,
  3;0,34,33;,
  3;0,35,34;,
  3;0,36,35;,
  3;0,37,36;,
  3;0,38,37;,
  3;0,39,38;,
  3;0,40,39;,
  3;0,41,40;,
  3;0,42,41;,
  3;0,43,42;,
  3;0,44,43;,
  3;0,45,44;,
  3;0,25,45;,
  3;23,46,47;,
  3;23,47,48;,
  3;23,48,49;,
  3;23,49,50;,
  3;23,50,51;,
  3;23,51,52;,
  3;23,52,53;,
  3;23,53,54;,
  3;23,54,55;,
  3;23,55,56;,
  3;23,56,57;,
  3;23,57,58;,
  3;23,58,59;,
  3;23,59,60;,
  3;23,60,61;,
  3;23,61,62;,
  3;23,62,63;,
  3;23,63,64;,
  3;23,64,65;,
  3;23,65,66;,
  3;23,66,67;,
  3;23,67,46;;
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
