#pragma once
static GLfloat spin_x = 0.0, spin_y = 0.0, spin_z = 0.0, k = 0.15, qd = 0.0, w = 0.0, id_x = 0.0, id_z = 0.0, spin_head = 0.0, k_head = 0.01, spin_z_head = 0.0,  k_z_head = 0.01;

int see = 0, k_see = 0;

// see = 0 => nhin giua; see = -1 => nhin phai; see = 1 => nhin trai
int mau_toc[] = { 42, 28, 13 };
int mau_mat_tim[] = { 65, 17, 152 };
int mau_mat_trang[] = { 229, 200, 185 };
int mau_mui[] = { 151, 90, 50 };
int mau_rau[] = { 69, 29, 4 };
int mau_ao[] = { 7, 183, 183 };
int mau_da[] = { 173, 132, 111 };
int mau_quan[] = { 66, 55, 156 };
int mau_giay[] = { 98, 98, 98 };
int mau_dat[] = { 146, 143, 55 };

void color_rgb(int color[])
{
	glColor3f((GLfloat)color[0] / 255, (GLfloat)color[1] / 255, (GLfloat)color[2] / 255);
}

void eye(int left_right, int see)
{
	glPushMatrix();
	glTranslatef(0, -0.5, 3.6);

		color_rgb(mau_mat_trang);
		glPushMatrix();
			glTranslatef(left_right * 2, 0, 0);
			glScalef(2, 0.999, 1);
			glutSolidCube(1);
		glPopMatrix();

		color_rgb(mau_mat_tim);
		glPushMatrix();
			glTranslatef(left_right * 1.5 + (see + left_right) / 2, 0, 0.1);
			glutSolidCube(1);
		glPopMatrix();

	glPopMatrix();
}

void hair(int left_right)
{
	color_rgb(mau_toc);
	glPushMatrix();
		glTranslatef(0, 3.1, 0);
		glScalef(1.01, 0.25, 1.01);
		glutSolidCube(8);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0, -1.6);
		glScalef(1.01, 0.53, 5.0 / 8);
		glutSolidCube(8);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(left_right * 3.5, 1.6, 3.589);
		glScalef(1.001, 1.03, 1.01);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(left_right * 3.5, 0.1, 3.499);
		glScalef(1.01, 2.03, 1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 1.6, 2);
		glScalef(1.01, 0.126, 0.3);
		glutSolidCube(8);
	glPopMatrix();
}

void head(GLfloat spin)
{
	// mặt
	color_rgb(mau_da);
	glPushMatrix();
		spin_z_head += k_z_head;
		if (spin_z_head >= 15 || spin_z_head <= -15) k_z_head = -k_z_head;
		glTranslatef(0, 6, 0);
		glRotatef(spin_z_head, 0, 0, 1);
	glPushMatrix();
		glTranslatef(0, 4, 0);
		//glRotatef(spin, 0, 1, 0);
		glutSolidCube(8);

		// mắt
		see += k_see;
		if (see == 1) k_see = -1;
		else if (see == -1) k_see = 1;
		eye(-1, see);
		eye(1, see);

		// mui
		color_rgb(mau_mui);
		glPushMatrix();
			glTranslatef(0, -1.5, 3.8);
			glScalef(2, 1, 1);
			glutSolidCube(1);
		glPopMatrix();

		// mieng
		color_rgb(mau_rau);
		glPushMatrix();
			glTranslatef(0, -3.5, 3.2);
			glScalef(4, 1.1, 2);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, -2.5, 3.7);
			glPushMatrix();
				glTranslatef(-1.5, 0, 0);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(1.5, 0, 0);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		// toc
		hair(1);
		hair(-1);

		glPushMatrix();
		int mau_non[] = { 168, 140, 81 };
		int mau_non_1[] = { 234, 201, 133 };
		color_rgb(mau_non);
		glTranslatef(0, 2.3, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(8, 7, 50, 30);
		color_rgb(mau_non_1);
		glutWireCone(8.1, 7.1, 20, 10);
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

// Ham ve canh tay: left_right = -1 => phai, left_right = 1 => trai
void hand(int left_right, GLfloat spin)
{
	color_rgb(mau_da);
	glPushMatrix();
		glTranslatef(5.5 * left_right, 6, 0);
		glRotatef(spin * left_right, 1, 0, 0);

		color_rgb(mau_ao);
		glPushMatrix();
			glTranslatef(0.5 * left_right, -2, 0);
			glScalef(1.01, 1.01, 1.01);
			glutSolidCube(4);
		glPopMatrix();

		color_rgb(mau_da);
		glPushMatrix();
			glTranslatef(0.5 * left_right, -6, 0);
			glScalef(1, 3, 1);
			glutSolidCube(4);
		glPopMatrix();

		if (left_right == 1)
		{
			glPushMatrix();
			glTranslatef(0.5 * left_right, -14.5, 0);
			glRotatef(-90, 0, 1, 0);
			int mau_hong[] = {243, 145, 127};
			color_rgb(mau_hong);
			glutSolidTeapot(4);
			glPopMatrix();
		}
	glPopMatrix();
}

void leg(int left_right, GLfloat spin)
{
	color_rgb(mau_quan);
	glPushMatrix();
		glTranslatef(2 * left_right, -6, 0);
		glRotatef(spin * left_right, 1, 0, 0);

		glPushMatrix();
			glTranslatef(0, -6, 0);
			glScalef(1, 3, 1);
			glutSolidCube(4);
		glPopMatrix();

		glPushMatrix();
			int mau_dau_goi[] = { 54, 45, 127 };
			color_rgb(mau_dau_goi);
			glTranslatef(0, -5.5, 1.51);
			glScalef(2, 1, 1);
			glutSolidCube(1);
		glPopMatrix();

		color_rgb(mau_giay);
		glPushMatrix();
			glTranslatef(0, -11, 0);
			glScalef(1.001, 0.501, 1.001);
			glutSolidCube(4);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, -9.5, -1);
			glScalef(1.001, 0.2501, 0.501);
			glutSolidCube(4);
		glPopMatrix();

	glPopMatrix();
}

void body()
{
	color_rgb(mau_ao);
	glPushMatrix();
		glScalef(1, 1.5, 0.5);
		glutSolidCube(8);
	glPopMatrix();

	color_rgb(mau_da);
	glPushMatrix();
		glTranslatef(0, 5.5, 1.89);
		glScalef(2, 1.1, 1.01);
		glutSolidCube(1);
	glPopMatrix();

	color_rgb(mau_quan);
	glPushMatrix();
		glTranslatef(0, -5, 0);
		glScalef(1.001, 0.26, 0.501);
		glutSolidCube(8);
	glPopMatrix();
}

void human_minecraft()
{
	if (w == 0)
	{
		spin_x = 0;
	}
	else
	{
		spin_x += k;
		if (spin_x >= 45 || spin_x <= -45) k = -k;

		qd = 3.14 * 12 / 180 * abs(k);
		GLfloat sin_w = sin(spin_y * 3.14159 / 180), cos_w = cos(spin_y * 3.14159 / 180);
		id_x += w * qd * sin_w;
		id_z += w * qd * cos_w;
	}

	glPushMatrix();
		glTranslatef(id_x, 18, id_z);
		glRotatef(spin_y, 0, 1, 0);
		glPushMatrix();
			
		spin_head += k_head;
		if (spin_head >= 20 || spin_head <= -20) k_head = -k_head;
			// dau
			head(spin_head);

			// than
			body();

			//tay phai
			hand(-1, -spin_x);

			//tay trai
			hand(1, -spin_x);

			//chan phai
			leg(-1, spin_x);

			//chan trai
			leg(1, spin_x);
		glPopMatrix();
	glPopMatrix();
}