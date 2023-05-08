#pragma once

bool proj = true;
int new_mouse = 0, mouse_rot = 1, mouse_trn = 0;

float turn = 50.0, tipp = 30.0, twst = 0.0, x_click = 0, y_click = 0, xtm = 0.0, ytm = 0.0, scl = 1.0;

void Keyboard(unsigned char ch, int x, int y)
{
	switch (ch) {
	case 'p':  
		proj = !proj;        
		break;
	case 'r':  
		mouse_trn = 0;
		mouse_rot = 1;
		break;
	case 't':  
		mouse_trn = 1;
		mouse_rot = 0;            
		break;
	case 'z':  
		turn = 0.0; 
		tipp = 0.0;
		scl = 1.0;         
		break;
	case '-':  
		scl *= 0.92;              
		break;
	case '+':  
		scl *= 1.06;              
		break;
	case  27:  
		exit(0);                 
		break;
	}
	glutPostRedisplay();
}

void OnSpecialKeyDown(int key, int xx, int yy)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		spin_y += 4;
		if (spin_y > 180) spin_y = -180;
		break;
	case GLUT_KEY_RIGHT:
		spin_y -= 4;
		if (spin_y < -180) spin_y = 180;
		break;
	case GLUT_KEY_UP:
		w = 1.0;
		break;
	case GLUT_KEY_DOWN:
		w = -1.0;
		break;
	}
	glutPostRedisplay();
}
void OnSpecialKeyUp(int key, int xx, int yy)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		w = 0;
		break;
	case GLUT_KEY_DOWN:
		w = 0;
		break;
	}
	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
	x_click = x;
	y_click = y;

	new_mouse = 1;
}

void Motion(int x, int y)
{
	float turn_del, tipp_del, x_del, y_del;

	static int c = 0, x_sav, y_sav;
	static float turn_save = 0.0, tipp_save = 0.0;

	if (new_mouse) {
		new_mouse = 0;
		x_sav = x_click;
		y_sav = y_click;
	}

	if (mouse_rot) {

		turn_del = x - x_sav;
		turn += turn_del;

		tipp_del = y - y_sav;
		tipp += tipp_del;

	}
	else if (mouse_trn) {

		x_del = float(x - x_sav) * 0.005;
		xtm += x_del;

		y_del = float(y - y_sav) * 0.005;
		ytm -= y_del;
	}

	x_sav = x;
	y_sav = y;

	glutPostRedisplay();
}