
#include <raylib.h>
#include <math.h>

Vector2 rotationalV(Vector2 x, Vector2 x1,float x2);
int main(){
    Vector2 center = {500,400};
    Vector2 v1,v2,rv1,rv2;
    v1 = {center.x,center.y+300};
    v2 = {center.x, center.y-300};
    float i =0;
    InitWindow(1080,780,"Rotation vector using rotation matrix test");

    SetTargetFPS(30);
    /**
     * The Update rate of the data in the condition !windowshouldclose() is dependent on the FPS. try removing the SettargetFPS or 
     * set a large value in its parameter to see the affect/consequence
     */

    while(!WindowShouldClose()){
        BeginDrawing();
        i = IsKeyDown(KEY_SPACE)? i+=0.5:i;


        // A line has two points, these two points must have its own rotational vector
        rv1 = rotationalV(v1,center,i);
        rv2 = rotationalV(v2,center,i);


        DrawCircleV(center,10,BLUE);
        DrawLineEx(rv1,rv2,10,ORANGE);
        EndDrawing();
        ClearBackground(BLACK);
    }
    CloseWindow();
}

Vector2 rotationalV(Vector2 a,Vector2 center,float n){ //rotational vector based on the rotational matrix model in wikipedia.
    Vector2 rot;
    rot.x = center.x+(a.x -center.x)*cos(n) - (a.y-center.y)*sin(n);
    rot.y = center.y+(a.x -center.x)*sin(n) + (a.y-center.y)*cos(n);
    return rot; //returns a rotational vector

}