#include<stdio.h>
#include<stdlib.h>

#pragma inline_depth(4)					//设置内联的深度
#pragma inline_recuresion(on)			//on off	//开启内联或者禁止内联
#pragma auto_line(on)					//自动开启内联，加快代码速度
#pragma hdrstop("1.pch")			
#pragma check_stack(on)					//off自动检查栈

//g全局优化,s,t	//代码体积与速度 y框架指针
#pragma optimize("g",on)				//代码优化

void main() {


	system("pause");
}