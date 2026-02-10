# include <stddef.h>
# include <unistd.h>

int bus_terminus(size_t nb_stops, const short bus_stops[nb_stops][2])
{
    int bus = 0; // 🚌 :p
    int i = 0;
    int j;
    while(i < nb_stops)
    {
        j = 0;
        while(j < 2)
        {
            if(j == 0)
                bus += bus_stops[i][j];
            if(j == 1)
                bus -= bus_stops[i][j];
            j++;
        }
        i++;
    }
    return bus;
}
/*
# include <stdio.h>
int main()
{
    size_t stops = 4;
    const short bus_stop[4][2] = { {5, 0}, {6, 2}, {1, 8}, {2, 3} };
    int bus = bus_terminus(stops, bus_stop);
    printf("%d\n", bus);
}
*/