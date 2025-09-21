class horario
{
public:
    horario(int h = 0, int m = 0, int s = 0);
    void sethorario(int h, int m, int s);
    void printUniversal();
    void printStandard();
    // getters
    int get_hour();
    int get_minute();
    int get_second();
    // setters
    void set_hour(int h);
    void set_minutes(int m);
    void set_seconds(int s);

private:
    int segundos = 0;
};