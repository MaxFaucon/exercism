namespace targets {
  class Alien {
  public:
    Alien(int x, int y) {
      x_coordinate = x;
      y_coordinate = y;
    }

    int x_coordinate{};

    int y_coordinate{};

    int get_health() { return health; }

    bool hit() {
      if (health > 0) {
        health -= 1;
      }

      return true;
    }

    bool is_alive() { return get_health() > 0; }

    bool teleport(int x_new, int y_new) {
      x_coordinate = x_new;
      y_coordinate = y_new;

      return true;
    }

    bool collision_detection(const Alien &alien) {
      return alien.x_coordinate == x_coordinate &&
             alien.y_coordinate == y_coordinate;
    }

  private:
    int health{3};
  };
} // namespace targets
