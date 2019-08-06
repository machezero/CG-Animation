//#include <stdlib.h>
#include <gl/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141
float sl =0,su=0;
float d = 1;
float c = 0.001;
float r = 0;
float BR = 0.878, BG = 1.000, BB = 1.000 ;
float CR = 0.498, CG = 1.000, CB = 0.831;
float SR = 1.000, SG = 1.000, SB = 0.000;
float S1R = 1, S1G = 0.549, S1B = 0;
float move1 = 0.5 , move2 = 0.5 , move3 = 0.5 ;
float movef1 = 50, movef2 = 45, movef3 = 20, movef4 = 10, movef5 = 10, movef6 = 30 ;
float movew1 = 0, movew2 = 0;
float movetf1 = 1, movetf2 = 1;
float mover1 = 3, mover2 = 0, mover3 = 6;
float speedw1 = 0.003 , speedw2 = -0.003;
float speedf1 = 0.001, speedf2 = -0.001;
float speeds = 0.003, speeds2 = -0.003;
float spin = 0.03;
float area = 1, area2 = 0;

void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius) //วงกลม
{
	GLint i;
	GLdouble theta;
	GLint circle_points = 100;

	glBegin(GL_POLYGON);
	for (i = 0; i < circle_points; i++)
	{
		theta = 2 * PI*i / circle_points ;
		glVertex2f(centerx + radius*cos(theta), centery + radius*sin(theta));
	}
	glEnd();
}
void MyOval2f(GLfloat centerx, GLfloat centery, GLfloat radiusx, GLfloat radiusy) //วงรี
{
	GLint i;
	GLdouble theta;
	GLint oval_points = 100;

	glBegin(GL_POLYGON);
	for (i = 0; i < oval_points; i++)
	{
		theta = 2 * PI*i / oval_points;
		glVertex2f(centerx + radiusx*cos(theta), centery + radiusy*sin(theta));
	}
	glEnd();
}
void MyHalfOval2f(GLfloat centerx, GLfloat centery, GLfloat radiusx, GLfloat radiusy) //วงรี
{
	GLint i;
	GLdouble theta;
	GLint oval_points = 100;

	glBegin(GL_POLYGON);
	for (i = 0; i < oval_points; i++)
	{
		theta = (2 * PI*i / oval_points)/2;
		glVertex2f(centerx + radiusx*cos(theta), centery + radiusy*sin(theta));
	}
	glEnd();
}
void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLoadIdentity();
	gluOrtho2D(0.0, 60.0, 0.0, 60.0);
}

void ship() //ตัวเรือ
{
	glColor3f(0.545, 0.271, 0.075);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex2d(30, 34);
			glVertex2d(40, 34);
			glVertex2d(39, 30);
			glVertex2d(36, 28);
			glVertex2d(34, 27);
			glVertex2d(26, 27);
			glVertex2d(24, 28);
			glVertex2d(21, 30);
			glVertex2d(20, 34);
			glEnd();
		}
	
	glColor3f(0, 0, 0); 
		glLineWidth(3);
		glBegin(GL_LINES);
		{
			glVertex2d(20.25, 33);
			glVertex2d(39.80, 33);
			glVertex2d(20.60, 32);
			glVertex2d(39.60, 32);
			glVertex2d(20.90, 31);
			glVertex2d(39.20, 31);
			glVertex2d(21, 30);
			glVertex2d(39, 30);
			glVertex2d(22.60, 29);
			glVertex2d(37.40, 29);
			glVertex2d(24, 28);
			glVertex2d(36, 28);
			glEnd();
		}

	glColor3f(0, 0, 0); 
		glLineWidth(4);
		glBegin(GL_LINE_STRIP);
		{
			glVertex2d(20, 34);
			glVertex2d(40, 34);
			glVertex2d(39, 30);
			glVertex2d(36, 28);
			glVertex2d(34, 27);
			glVertex2d(26, 27);
			glVertex2d(24, 28);
			glVertex2d(21, 30);
			glVertex2d(20, 34);
			glEnd();
		}
}
void canvas() //เสาเรือ
{
	glPushMatrix();
	glTranslated(30, 36, 0);
	glColor3f(0.863, 0.863, 0.863);
	glBegin(GL_TRIANGLES);
	{
		glVertex2d(0, 0);
		glVertex2d(0, 15);
		glVertex2d(-10, 0);
		glEnd();
	}
	
	glColor3f(0, 0, 0);
	glLineWidth(3.7);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 0);
		glVertex2d(0, 15);
		glVertex2d(-10, 0);
		glEnd();
	}
	glColor3f(1.000, 0.843, 0.000);
	glBegin(GL_QUADS);
	{
		glVertex2d(0, 0);
		glVertex2d(0, 2);
		glVertex2d(-8.68,2);
		glVertex2d(-10, 0);
		glEnd();
	}
	glColor3f(0, 0, 0);
	glLineWidth(3.7);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 0);
		glVertex2d(0, 2);
		glVertex2d(-8.68, 2);
		glVertex2d(-10, 0);
		glEnd();
	}

	glColor3f(1.000, 0.843, 0.000);
	glBegin(GL_QUADS);
	{
		glVertex2d(0, 4);
		glVertex2d(0, 6);
		glVertex2d(-6, 6);
		glVertex2d(-7.35, 4);
		glEnd();
	}
	glColor3f(0,0,0);
	glLineWidth(3.7);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 4);
		glVertex2d(0, 6);
		glVertex2d(-6, 6);
		glVertex2d(-7.35, 4);
		glEnd();
	}

	glColor3f(1.000, 0.843, 0.000);
	glBegin(GL_QUADS);
	{
		glVertex2d(0, 8);
		glVertex2d(0, 10);
		glVertex2d(-3.4, 10);
		glVertex2d(-4.69, 8);
		glEnd();
	}
	glColor3f(0, 0, 0);
	glLineWidth(3.7);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 8);
		glVertex2d(0, 10);
		glVertex2d(-3.4, 10);
		glVertex2d(-4.69, 8);
		glEnd();
	}

	glColor3f(1.000, 0.843, 0.000);
	glBegin(GL_QUADS);
	{
		glVertex2d(0, 12);
		glVertex2d(0, 15);
		glVertex2d(0, 15);
		glVertex2d(-2, 12);
		glEnd();
	}
	glColor3f(0, 0, 0);
	glLineWidth(3.7);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 12);
		glVertex2d(0, 15);
		glVertex2d(0, 15);
		glVertex2d(-2, 12);
		glEnd();
	}
	glPopMatrix();
}
void mast() //ผ่าใบเรือ
{
	glPushMatrix();
	glTranslated(30, 34, 0);
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_QUADS);
	{
		glVertex2d(0, 0);
		glVertex2d(0, 17);
		glVertex2d(0.8, 17);
		glVertex2d(0.8, 0);
		glEnd();
	}
	glColor3f(0, 0, 0);
	glLineWidth(3.7);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 0);
		glVertex2d(0, 17);
		glVertex2d(0.8, 17);
		glVertex2d(0.8, 0);
		glEnd();
	}
	glPopMatrix();
}
void hat()
{

	glPushMatrix();
	glTranslated(35,41.8,0);
	glRotated(30, 0, 0, 1);
	glColor3f(0, 0, 0);
	MyHalfOval2f(0, 0, 3.3, 2.3);
	glColor3f(1.000, 0.843, 0.000);
	MyHalfOval2f(0,0,3,2);
	glPopMatrix();


	glPushMatrix();
	glTranslated(35.57, 40.9, 0);
	glRotated(30, 0, 0, 1);
	glColor3f(0, 0, 0);
	MyHalfOval2f(0, 0, 3.8, 2.3);
	glColor3f(1, 0, 0);
	MyHalfOval2f(0, 0, 3.5, 2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(35.5, 41, 0);
	glRotated(30, 0, 0, 1);
	glColor3f(0, 0, 0);
	MyOval2f(0, 0, 4.8, 1.3);
	glColor3f(1.000, 0.647, 0.000);
	MyOval2f(0, 0, 4.5, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(36.2, 39.7, 0);
	glRotated(30, 0, 0, 1);
	glColor3f(0, 0, 0);
	MyHalfOval2f(0, 0, 3, 2);
	glPopMatrix();
}
void stickman() //คน
{
	glColor3f(0, 0, 0);
	MyCircle2f(36,40,3); //head

	glLineWidth(1000);
	glBegin(GL_LINES); //body
	{
		glVertex2d(36,40);
		glVertex2d(35,32);
		glEnd();
	}

	MyCircle2f(39, 37, 0.5);
	glBegin(GL_LINE_STRIP); //hand
	{
		glLineWidth(100);
		glVertex2d(35.40,36.4);
		glVertex2d(39,37);
		glVertex2d(35.20,34.6);
		glEnd();
	}
}
void FishingHook() //เบ็ดตกปลา
{
	glColor3f(0,0,0);
	glPointSize(3);
	glBegin(GL_POINTS);
	{
		glVertex2d(44.9,44);
		glVertex2d(42, 40.78);
		glVertex2d(40, 38.38);
		glEnd();
	}

	glColor3f(0.5, 0.2, 0.07);
	glLineWidth(3);
	glBegin(GL_LINES); //คันเบ็ดตกปลา
	{
		glVertex2d(39, 37);
		glVertex2d(45, 44);
		glEnd();
	}
}
void FishingHook2() //เอ็นตกปลา
{
	glColor3f(0,0,0);
	glLineWidth(1);
	glBegin(GL_LINES); //เอ็นตกปลา
	{
		glVertex2d(45,44);
		glVertex2d(45,su+22);
		glEnd();
	}
	glPushMatrix();
	glTranslated(0,su,0);
	MyCircle2f(45,22,0.25);
	glBegin(GL_TRIANGLES); //ตะขอ
	{
		glVertex2d(45,22);
		glVertex2d(45.40,21.50);
		glVertex2d(46,21.50);
		glVertex2d(45.80,22);
		glVertex2d(45.40,21.50);
		glVertex2d(45,22);
		glEnd();
	}
	glPopMatrix();
}
void warter() //น้ำ
{
	glBegin(GL_QUADS);
	{
		glColor3f(0.098, 0.098, 0.439);
		glVertex2d(0,0);
		glVertex2d(60,0);
		glColor3f(0.000, 0.749, 1.000);
		glVertex2d(60,29);
		glVertex2d(0,29);
		glEnd();
	}
}
void warter1() //คลื่นน้ำ
{
	glColor3f(0, 0, 0);
	MyOval2f(8, 28, 10.5, 4.5);

	glColor3f(0.000, 0.749, 1.000);
	MyOval2f(8, 28, 10, 4);
}
void warter2() //คลื่นน้ำ
{
	glColor3f(0, 0, 0);
	MyOval2f(24, 28, 10, 4.5);

	glColor3f(0.000, 0.749, 1.000);
	MyOval2f(24, 28, 9.5, 4);
}
void warter3() //คลื่นน้ำ
{
	glColor3f(0, 0, 0);
	MyOval2f(40, 27.8, 8.5, 3.5);

	glColor3f(0.000, 0.749, 1.000);
	MyOval2f(40, 27.8, 8, 3);
}
void warter4() //คลื่นน้ำ
{
	glColor3f(0, 0, 0);
	MyOval2f(53, 27.9, 9.5, 4.5);

	glColor3f(0.000, 0.749, 1.000);
	MyOval2f(53, 27.9, 9, 4);

}
void stone() //ก้อนหิน
{
	glColor3f(0.412, 0.412, 0.412);
	glBegin(GL_POLYGON);
	{
		glVertex2d(0,0);
		glVertex2d(0,4);
		glVertex2d(2,5);
		glVertex2d(4,5);
		glVertex2d(5,4.6);
		glVertex2d(6,4.4);
		glVertex2d(7,3.4);
		glVertex2d(7.6,2);
		glVertex2d(8,0);
		glVertex2d(0,0);
		glEnd();
	}

	
	glColor3f(0,0,0);
	glLineWidth(5);
	glBegin(GL_LINES);
	{
		glVertex2d(0, 4);
		glVertex2d(2, 5);
		glVertex2d(2, 5);
		glVertex2d(4, 5);
		glVertex2d(4, 5);
		glVertex2d(5, 4.6);
		glVertex2d(5, 4.6);
		glVertex2d(6, 4.4);
		glVertex2d(6, 4.4);
		glVertex2d(7, 3.4);
		glVertex2d(7, 3.4);
		glVertex2d(7.6, 2);
		glVertex2d(7.6, 2);
		glVertex2d(8, 0);
		glEnd();
	}

	glColor3f(0.502, 0.502, 0.502);
	glBegin(GL_POLYGON);
	{
		glVertex2d(8,0);
		glVertex2d(7.6,2);
		glVertex2d(9,2.6);
		glVertex2d(10,2);
		glVertex2d(11,2.4);
		glVertex2d(12,3);
		glVertex2d(13,3);
		glVertex2d(14.4,1.8);
		glVertex2d(15,0);
		glVertex2d(8,0);
		glEnd();
	}

	glColor3f(0,0,0);
	glLineWidth(5);
	glBegin(GL_LINES);
	{
		glVertex2d(8, 0);
		glVertex2d(7.6, 2);
		glVertex2d(7.6, 2);
		glVertex2d(9, 2.6);
		glVertex2d(9, 2.6);
		glVertex2d(10, 2);
		glVertex2d(10, 2);
		glVertex2d(11, 2.4);
		glVertex2d(11, 2.4);
		glVertex2d(12, 3);
		glVertex2d(12, 3);
		glVertex2d(13, 3);
		glVertex2d(13, 3);
		glVertex2d(14.4, 1.8);
		glVertex2d(14.4, 1.8);
		glVertex2d(15, 0);
		glEnd();
	}
}
void stone1()
{
	glColor3f(0.663, 0.663, 0.663);
	glBegin(GL_POLYGON);
	{
		glVertex2d(22,0);
		glVertex2d(22.6,0.6);
		glVertex2d(22.2,1);
		glVertex2d(23,2);
		glVertex2d(23.8,2.6);
		glVertex2d(24.4,2.8);
		glVertex2d(25.4,2.6);
		glVertex2d(26,3);
		glVertex2d(27.4,2.8);
		glVertex2d(28.4,2.4);
		glVertex2d(29.4,2.8);
		glVertex2d(30.2,2);
		glVertex2d(31,1.6);
		glVertex2d(31.2,0);
		glEnd();
	}
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINES);
	{
		glVertex2d(22, 0);
		glVertex2d(22, 0.6);
		glVertex2d(22, 0.6);
		glVertex2d(22.2, 1);
		glVertex2d(22.2, 1);
		glVertex2d(23, 2);
		glVertex2d(23, 2);
		glVertex2d(23.8, 2.6);
		glVertex2d(23.8, 2.6);
		glVertex2d(24.4, 2.8);
		glVertex2d(24.4, 2.8);
		glVertex2d(25.4, 2.6);
		glVertex2d(25.4, 2.6);
		glVertex2d(26, 3);
		glVertex2d(26, 3);
		glVertex2d(27.4, 2.8);
		glVertex2d(27.4, 2.8);
		glVertex2d(28.4, 2.4);
		glVertex2d(28.4, 2.4);
		glVertex2d(29.4, 2.8);
		glVertex2d(29.4, 2.8);
		glVertex2d(30.2, 2);
		glVertex2d(30.2, 2);
		glVertex2d(31, 1.6);
		glVertex2d(31, 1.6);
		glVertex2d(31.2, 0);
		glEnd();
	}
}
void rain() //ฝน
{
	glColor3f(0,0,0);
	glLineWidth(1.5);
	glBegin(GL_LINES);
	{
		glVertex2d(0,0);
		glVertex2d(0,6);
		glEnd();
	}

}

void finsfish(float R, float G, float B, float R1, float G1, float B1) //คีบตัว
{
	glPushMatrix();
	glTranslated(0, -0.6, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP); //คีบตัว
	{
		glVertex2f(0, 0.3);
		glVertex2f(0, 1);
		glVertex2f(1, 1.3);
		glVertex2f(1, 0);
		glEnd();
	}
	glColor3f(R1-0.4, G1, B1); 
	glBegin(GL_POLYGON);
	{
		glVertex2f(0, 0.3);
		glVertex2f(0, 1);
		glVertex2f(1, 1.3);
		glVertex2f(1, 0);
		glEnd();
	}
	glPopMatrix();
}
void fish(float R, float G, float B, float R1, float G1, float B1)
{
	glPushMatrix();
	glTranslated(2.6, 0, 0);
	glLineWidth(3);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //คีบหาง
	{
		glVertex2d(0, 0);
		glVertex2d(1.8, 2);
		glVertex2d(1.8, -2);
		glEnd();
	}
	glColor3f(R1-0.4, G1, B1);
	glBegin(GL_TRIANGLES); //คีบหาง
	{
		glVertex2d(0,0);
		glVertex2d(1.8,2);
		glVertex2d(1.8,-2);
		glEnd();
	}
	
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.8,0.7,0);
	glColor3f(R1 - 0.4, G1, B1);
	glBegin(GL_POLYGON); //คีบหัว
	{
		glVertex2d(0,0);
		glVertex2d(1.8,0);
		glVertex2d(2.4,1.4);
		glVertex2d(-0.6,1.4);
		glEnd();
	}

	glColor3f(0, 0, 0);
	glLineWidth(2.2);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(0, 0);
		glVertex2d(1.8, 0);
		glVertex2d(2.4, 1.4);
		glVertex2d(-0.6, 1.4);
		glEnd();
	}
	glPopMatrix();
	
	glColor3f(0, 0, 0);
	MyOval2f(0, 0, 3, 1.7);
	glColor3f(R,G,B);
	MyOval2f(0,0,2.8,1.5); //ตัวปลา

	glPushMatrix();
	glTranslated(-1.5,0.7,0);
	glColor3f(0, 0, 0);//ตาปลา
	MyCircle2f(0, 0, 0.65);
	glColor3f(1,1,1);
	MyCircle2f(0,0,0.5);
	glColor3f(0, 0, 0);
	MyCircle2f(0, 0, 0.25);
	glPopMatrix();

	glPushMatrix();
	glRotated(movetf1,0,0,1);
	finsfish( R, G, B, R1, G1, B1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-2.8,-0.4,0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES); //ปาก
	{
		glVertex2f(0,0);
		glVertex2f(1.7,0);
		glEnd();
	}
	glPopMatrix();
	
}
void cloud1()
{
	glPushMatrix();
	glTranslated(20, 5, 1);
	glColor3f(0,0,0);
	MyCircle2f(30, 50, 3.4);
	MyOval2f(26, 49.5, 4.4, 2.4);
	MyOval2f(33, 49.8, 4.4, 2.2);

	glColor3f(CR,CG,CB);
	MyCircle2f(30,50,3);
	MyOval2f(26,49.5,4,2);
	MyOval2f(33, 49.8, 4, 1.8);
	glPopMatrix();
}
void cloud2()
{
	glPushMatrix();
	glTranslated(-10, -1, 1);
	glColor3f(0, 0, 0);
	MyOval2f(30,51,4.4,3.4);
	MyOval2f(25, 49.5, 4.4, 2.4);
	MyOval2f(35, 49.8, 4.4, 2.2);

	glColor3f(CR, CG, CB);
	MyOval2f(30, 51, 4, 3);
	MyOval2f(25, 49.5, 4, 2);
	MyOval2f(35, 49.8, 4, 1.8);
	glPopMatrix();
}
void cloud3()
{
	glPushMatrix();
	glTranslated(15, -12, 1);
	glColor3f(0, 0, 0);
	MyOval2f(30, 51, 4.4, 3.4);
	MyOval2f(35, 49.8, 4.4, 2.2);

	glColor3f(CR, CG, CB);
	MyOval2f(30, 51, 4, 3);
	MyOval2f(35, 49.8, 4, 1.8);
	glPopMatrix();
}	 
void sun1()
{
	glPushMatrix();
	glTranslatef(0,4,0);
	glColor3f(SR, SG, SB);
	glBegin(GL_TRIANGLES);
	{
		glVertex2d(-1,0);
		glVertex2d(0,1);
		glVertex2d(1,0);
		glEnd();
	}
	glColor3f(S1R, S1G, S1B);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2d(-1, 0);
		glVertex2d(0, 1);
		glVertex2d(1, 0);
		glEnd();
	}
	glPopMatrix();
}
void sun()
{
	glColor3f(S1R, S1G, S1B);
	MyCircle2f(0,0,3.3);
	glColor3f(SR,SG,SB);
	MyCircle2f(0,0,3);

	glPushMatrix();
	glRotated(45,0,0,1);
	sun1();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0 , 0, 1);
	sun1();
	glPopMatrix();

	glPushMatrix();
	glRotated(135, 0, 0, 1);
	sun1();
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 0, 0, 1);
	sun1();
	glPopMatrix();

	glPushMatrix();
	glRotated(225, 0, 0, 1);
	sun1();
	glPopMatrix();

	glPushMatrix();
	glRotated(270, 0, 0, 1);
	sun1();
	glPopMatrix();

	glPushMatrix();
	glRotated(315, 0, 0, 1);
	sun1();
	glPopMatrix();

	
	glPushMatrix();
	glTranslated(13, 51, 0);
	glTranslated(-13, -51, 0);
	sun1();
	glPopMatrix();
	
}

void all()
{
	spin += 0.03;
	if (area >= 1.3){ speeds = -0.0003; }
	if (area <= 1){ speeds = 0.0003; }
	area = area + speeds;

	move1 = move1 + 0.008;
	if (move1 >= 30){
		move1 = -60;
	}
	move2 = move2 + 0.011;
	if (move2 >= 55){
		move2 = -40;
	}
	move3 = move3 + 0.007;
	if (move3 >= 30){
		move3 = -58;
	}

	movef1 = movef1 - 0.015;
	if (movef1 <= -10){
		movef1 = 70;
	}
	movef2 = movef2 - 0.011;
	if (movef2 <= -7){
		movef2 = 70;
	}
	movef3 = movef3 - 0.015;
	if (movef3 <= -10){
		movef3 = 70;
	}
	movef4 = movef4 - 0.016;
	if (movef4 <= -10){
		movef4 = 70;
	}
	movef5 = movef5 - 0.015;
	if (movef5 <= -10){
		movef5 = 70;
	}
	movef6 = movef6 - 0.0182;
	if (movef6 <= -10){
		movef6 = 70;
	}
	if (movew1 <= -2){
		speedw1 = 0.003;
	}

	else if (movew1 >= 1){
		speedw1 = -0.003;
	}
	movew1 += speedw1;

	if (movew2 <= -2){
		speedw2 = 0.003;
	}

	else if (movew2 >= 1){
		speedw2 = -0.003;
	}
	movew2 += speedw2;

	//-------------
	if (movetf1 <= 10){
		speedf1 += 0.001;
	}

	else if (movetf1 >= -10){
		speedf1 += -0.001;
	}
	movetf1 += speedf1;

	if (movetf2 <= 10){
		speedf2 += 0.001;
	}

	else if (movetf2 >= -10){
		speedf2 += -0.001;
	}
	movetf2 += speedf2;
	
	//-------------------------
	mover1 = mover1 - 0.1;
	if (mover1 <= 15){
		mover1 = 70;
	}

	mover2 = mover2 - 0.09;
	if (mover2 <= 15){
		mover2 = 70;
	}

	mover3 = mover3 - 0.07;
	if (mover3 <= 15){
		mover3 = 70;
	}
	
	glutPostRedisplay();
}
void movecloud()
{
	move1 = move1 + 0.008;
	if (move1 >= 30){
		move1 = -60;
	}
	move2 = move2 + 0.011;
	if (move2 >= 55){
		move2 = -40;
	}
	move3 = move3 + 0.007;
	if (move3 >= 30){
		move3 = -58;
	}
	glutPostRedisplay();
}
void movefish()
{
	movef1 = movef1 - 0.015;
	if (movef1 <= -10){
		movef1 = 70;
	}
	movef2 = movef2 - 0.011;
	if (movef2 <= -7){
		movef2 = 70;
	}
	movef3 = movef3 - 0.015;
	if (movef3 <= -10){
		movef3 = 70;
	}
	movef4 = movef4 - 0.016;
	if (movef4 <= -10){
		movef4 = 70;
	}
	movef5 = movef5 - 0.015;
	if (movef5 <= -10){
		movef5 = 70;
	}
	movef6 = movef6 - 0.0182;
	if (movef6 <= -10){
		movef6 = 70;
	}
	//-------------
	if (movetf1 <= 10){
		speedf1 += 0.001;
	}

	else if (movetf1 >= -10){
		speedf1 += -0.001;
	}
	movetf1 += speedf1;

	if (movetf2 <= 10){
		speedf2 += 0.001;
	}

	else if (movetf2 >= -10){
		speedf2 += -0.001;
	}
	movetf2 += speedf2;
	
	//printf("area = %f \n", movetf1);

	glutPostRedisplay();
}
void movewarter()
{
	if (movew1 <= -2){
		speedw1 = 0.003;
	}
	
	else if (movew1 >= 1){
		speedw1 = -0.003;
	}
	movew1 += speedw1;
	
	if (movew2 <= -2){
		speedw2 = 0.003;
	}

	else if (movew2 >= 1){
		speedw2 = -0.003;
	}
	movew2 += speedw2;

	glutPostRedisplay();
}
void spinthesun()
{
	spin += 0.03;

	if (area >= 1.3){ speeds = -0.0003; }
	if (area <= 1){ speeds = 0.0003; }
	area = area + speeds;
	glutPostRedisplay();
} 
void runrain()
{
	mover1 = mover1 - 0.1;
	if (mover1 <= 15){
		mover1 = 70;
	}

	mover2 = mover2 - 0.09;
	if (mover2 <= 15){
		mover2 = 70;
	}

	mover3 = mover3 - 0.07;
	if (mover3 <= 15){
		mover3 = 70;
	}

	glutPostRedisplay();
}

void mainmenu(int key)  
{
	switch (key){
	case 1:
		glutIdleFunc(movecloud);
		break;
	case 2:
		glutIdleFunc(movefish);
		break;
	case 3:
		glutIdleFunc(movewarter);
		break;
	case 4:
		glutIdleFunc(spinthesun);
		break;
	case 5:
		glutIdleFunc(runrain);
		break;
		
	case 6:
		glutIdleFunc(all);
		
	 	break;
	case 0: exit(0);
		break;
	}
	glutPostRedisplay();
}
void specialkey(int key ,int x , int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: sl -= 1;
		break;
	case GLUT_KEY_RIGHT: sl += 1;
		break;
	case GLUT_KEY_DOWN: su -= d;
		break;
	case GLUT_KEY_UP: su += d;
		if (su<22){
			su += d;
		}
		else if(su >= 22){
			su = su -22;
		}
		//printf("su = %f \n",su);
		break;
	}
	
	glutPostRedisplay();
}
void keyboard(unsigned char key ,int x ,int y)
{
	switch (key)
	{
	case 'r': 
		r = 1;
		if (BR >= 0.812){ BR -= 0.005; }
		if (BG >= 0.812){ BG -= 0.005; }
		if (BB >= 0.812){ BB -= 0.005; }
		
		if (CR >= 0.612){ CR -= 0.005; }
		if (CG >= 0.612){ CG -= 0.005; }
		if (CB >= 0.612){ CB -= 0.005; }

		if (SR >= 0.810){ SR -= 0.025; }
		if (SG >= 0.810){ SG -= 0.025; }
		if (SB <= 0.810){ SB += 0.025; }

		if (S1R >= 0.810){ S1R -= 0.025; }
		if (S1G <= 0.810){ S1G += 0.025; }
		if (S1B <= 0.810){ S1B += 0.025; }
		break;

	case 'R':
		r = 1;
		if (BR >= 0.812){ BR -= 0.005; }
		if (BG >= 0.812){ BG -= 0.005; }
		if (BB >= 0.812){ BB -= 0.005; }

		if (CR >= 0.612){ CR -= 0.005; }
		if (CG >= 0.612){ CG -= 0.005; }
		if (CB >= 0.612){ CB -= 0.005; }

		if (SR >= 0.810){ SR -= 0.025; }
		if (SG >= 0.810){ SG -= 0.025; }
		if (SB <= 0.810){ SB += 0.025; }

		if (S1R >= 0.810){ S1R -= 0.025; }
		if (S1G <= 0.810){ S1G += 0.025; }
		if (S1B <= 0.810){ S1B += 0.025; }
		break;

	case 's':
		r = 0;
		if (BR >= 0.878){ BR -= 0.005; }
		if (BG <= 1.000){ BG += 0.005; }
		if (BB <= 1.000){ BB += 0.005; }

		if (CR >= 0.498){ CR -= 0.005; }
		if (CG <= 1.000){ CG += 0.005; }
		if (CB >= 0.831){ CB -= 0.005; }

		if (SR <= 1.000){ SR += 0.005; }
		if (SG <= 1.000){ SG += 0.005; }
		if (SB >= 0.000){ SB -= 0.005; }

		if (S1R <= 1.000){ S1R += 0.005; }
		if (S1G >= 0.549){ S1G -= 0.005; }
		if (S1B >= 0.000){ S1B -= 0.005; }
		break;

	case 'S':
		r = 0;
		if (BR >= 0.878){ BR -= 0.005; }
		if (BG <= 1.000){ BG += 0.005; }
		if (BB <= 1.000){ BB += 0.005; }

		if (CR >= 0.498){ CR -= 0.005; }
		if (CG <= 1.000){ CG += 0.005; }
		if (CB >= 0.831){ CB -= 0.005; }

		if (SR <= 1.000){ SR += 0.005; }
		if (SG <= 1.000){ SG += 0.005; }
		if (SB >= 0.000){ SB -= 0.005; }

		if (S1R <= 1.000){ S1R += 0.005; }
		if (S1G >= 0.549){ S1G -= 0.005; }
		if (S1B >= 0.000){ S1B -= 0.005; }
		break;
	}
	glutPostRedisplay();
}

void display(void){
	glClearColor(BR, BG, BB,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//------------------- พระอาทิต
	glPushMatrix();
	glTranslated(14,51,0);
	glScaled(area,area,1);
	glRotated(spin,0,0,1);
	glTranslated(0, 0, 0);
	sun();
	glPopMatrix();

	//------------------- ก้อนเมฆ
	glPushMatrix();
	glTranslated(move1,0,0);
	cloud1();
	glPopMatrix();
	glPushMatrix();
	glTranslated(move2, 0, 0);
	cloud2();
	glPopMatrix();
	glPushMatrix();
	glTranslated(move3, 0, 0);
	cloud3();
	glPopMatrix();


	//------------------- ตัวเรือ
	glPushMatrix();
	glTranslated(sl,0,0);
	glTranslated(0,movew1,0);
	stickman();
	FishingHook();
	mast();
	canvas();
	hat();
	ship();
	glPopMatrix();
	
	//------------------ ฝน
	if (r>0){
		glPushMatrix();
		glTranslated(mover1, mover1, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(10, 5, 0);
		rain();
		glPopMatrix();

		glPushMatrix();
		glTranslated(mover2, mover2, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(0, 10, 0);
		rain();
		glPopMatrix();

		glPushMatrix();
		glTranslated(mover3, mover3, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-10, 10, 0);
		rain();
		glPopMatrix();

		glPushMatrix();
		glTranslated(mover1, mover1, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-18, 5, 0);
		rain();
		glPopMatrix();

		glPushMatrix();
		glTranslated(mover2, mover2, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-25, 10, 0);
		rain();
		glPopMatrix();

		glPushMatrix();
		glTranslated(mover3, mover3, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-30, 5, 0);
		rain();
		glPopMatrix();

		glPushMatrix();
		glTranslated(mover1, mover1, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-35, 5, 0);
		rain();
		glPopMatrix();
	}
	//------------------ คลื่นน้ำ
	glPushMatrix();
	glTranslated(0,movew1,0);
	warter1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,movew1,0);
	warter3();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,movew2,0);
	warter2();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,movew2,0);
	warter4();
	glPopMatrix();
	warter();
	
	//------------------ คันเบ็ต
	glPushMatrix();
	glTranslated(sl, 0, 0);
	glTranslated(0, movew1, 0);
	FishingHook2();
	glPopMatrix();

	//------------------- ปลา
	glPushMatrix();
	glTranslated(movef1,22,0);
	glScaled(1.5, 2, 1);
	fish(1.000, 0.078, 0.576, 0.545, 0.000, 0.545);
	glPopMatrix();

	glPushMatrix();
	glTranslated(movef2, 8, 0);
	glScaled(1, 1.5, 1);
	fish(0.000, 1.000, 0.000, 0.737, 0.561, 0.561);
	glPopMatrix();

	glPushMatrix();
	glTranslated(movef3, 26, 0);
	glScaled(1.5, 1, 1);
	fish(1.000, 0.843, 0.000, 0.698, 0.133, 0.133);
	glPopMatrix();

	glPushMatrix();
	glTranslated(movef4, 18, 0);
	glScaled(1.5, 1.8, 1);
	fish(0.600, 0.196, 0.800, 0.498, 1.000, 0.000);
	glPopMatrix();

	glPushMatrix();
	glTranslated(movef5, 9, 0);
	glScaled(1.2, 2, 1);
	fish(0.000, 1.000, 1.000, 0.000, 0.545, 0.545);
	glPopMatrix();

	glPushMatrix();
	glTranslated(movef6, 15, 0);
	glScaled(1.5, 2, 1);
	fish(0.412, 0.412, 0.412, 1.000, 0.973, 0.863);
	glPopMatrix();
	//------------------- ก้อนหิน
	glPushMatrix();
	glTranslatef(-12,-1,0);
	glScalef(1.5, 1.5, 1);
	stone1();
	glPopMatrix();
	glPushMatrix();
	glScalef(1.5,1.5,1);
	stone();
	glPopMatrix();
	glPushMatrix();
	glScalef(1.5, 1.5, 1);
	glTranslatef(43,-1.5,0);
	glRotatef(180,0,1,0);
	stone();
	glPopMatrix();
	glPushMatrix();
	glScalef(1.5, 1.5, 1);
	glTranslatef(43, -1, 0);
	glRotatef(180, 0, 1, 0);
	stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2,-1, 0);
	glScalef(1.5, 1.5, 1);
	stone1();
	glPopMatrix();
	//--------------
	
	glFlush();
	glutSwapBuffers();
	
}
void txt()
{
	printf("***This is Luffy's fishing boat ride.***   \n\n");
	printf("Program functionality key \n");
	printf("1.Hold down 'R' or 'r' for rainy season. \n");
	printf("2.Hold down 'S' or 's' for summer season.\n");
	printf("3.Press key UP for Fishing nets  up. \n");
	printf("4.Press key DOWN for Fishing nets down. \n");
	printf("5.Press key LEFT for ship to the left. \n");
	printf("5.Press key RIGHT for ship to the right. \n\n");
	printf("Program functionality mouse \n");
	printf("1.Right click for Show Menu run animation \n");
	printf("-- Play Cloud  \n");
	printf("-- Play Fish  \n");
	printf("-- Play Warter  \n");
	printf("-- Play The Sun  \n");
	printf("-- Play All  \n");
	printf("-- Exit \n");
	printf("2.Left click for Enter menu \n\n");
	printf("***IF Select menu 'Play All' and hold down 'R' or 'r' to rain. *** ");
	
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(30, 40);
	glutCreateWindow("Porject CG");
	gluOrtho2D(0,60,0,60);
	glutCreateMenu(mainmenu);
	glutAddMenuEntry("Play Cloud", 1);
	glutAddMenuEntry("Play Fish", 2);
	glutAddMenuEntry("Play Warter", 3);
	glutAddMenuEntry("Play The Sun", 4);
	glutAddMenuEntry("Play All", 6);
	glutAddMenuEntry("Exit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	txt();
	glutSpecialFunc(specialkey);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}