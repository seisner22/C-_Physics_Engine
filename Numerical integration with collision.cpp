//Here is a script of an object endlessly falling due to gravity.
//The way this works is that the motion of the ball is described completely
//by it's 3 position coordinates (x, y, z) and it's 3 momentum coordinates
//For a ball under gravity where gravity acts in the z direction (downard),
//it is easy to start with an initial height and just subtract 9.81*t^2 where t is the time
//However, that doesn't work well for more complicated things, so we use differential equations
//For a particle under gravity, we have:
//dz/dt = (1/m)p (the z position is the derivative of velocity)
//dp/dt = -g (Newton's second law, where the force is just gravity)

//to integrate these we use Euler's method. To do this we start with an initial condition and update it:

int main(){


  float z = 10.0f; //initial height of 10m

  float p = 0.0f; //initial momentum of 0 kg m /s

  float m = 1.0f; // mass of 1 kg

  float g = 9.81f;

  float dt = 0.01f; //size of a time step (computer's cannot do time continuously so we set a very small time step)

  float dz;

  float dp;

  int bool_collide;

  float f_collide;

  for (i=0; i<=1000; i++){ //we will update this for 1000 frames ()
    dz = (1.0f/m)*p;

    dp = -g;

    bool_collide = is_collide(z);

    f_collide = (-1.0f/dt)*(p + p);

    dp = dp + (float)bool_collide*f_collide;

    p = p + dp*dt; //This is Euler's method for integrating a differential equation

    z = z + dz*dt;
  }

  return 0;
}

//Now at each step in time we have the new momentum and more importantly the new position. We can store the values
//and use them to plot a solution or plot the motion.

int is_collide(float h){

    if (h <= 0.0f){
      return 1;
    }

    else{
      return 0;
    }

}
