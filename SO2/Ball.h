class Ball
{
    double volacity;
    bool goDown;
    bool goRight;
    int x_position;
    int y_position;
    public:
    Ball(double volacity, int x_position, int y_position, bool goDown, bool goRight);
    void Update();
    double getVolacity();
    void setVolacity(double volacity);
    int getXPosition();
    void setXPosition(int x_position);
    int getYPosition();
    void setYPosition(int y_position);
    bool getGoDown();
    void setGoDown(bool goDown);
    bool getGoRight();
    void setGoRight(bool goRight);
};

