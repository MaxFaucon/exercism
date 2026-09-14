namespace hellmath {

  enum class AccountStatus { troll = 1, guest = 2, user = 3, mod = 4 };

  enum class Action { read, remove, write };

  bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll) {
      return viewer == AccountStatus::troll;
    }

    return true;
  }

  bool permission_check(Action action, AccountStatus account_status) {
    switch (account_status) {
    case AccountStatus::mod:
      return true;
    case AccountStatus::user:
    case AccountStatus::troll:
      return action == Action::read || action == Action::write;
    default:
      return action == Action::read;
    }
  }

  bool valid_player_combination(AccountStatus first_player,
                                AccountStatus second_player) {
    if (first_player == AccountStatus::guest ||
        second_player == AccountStatus::guest) {
      return false;
    }

    if (first_player == AccountStatus::troll ||
        second_player == AccountStatus::troll) {
      return first_player == second_player;
    }

    return true;
  }

  bool has_priority(AccountStatus first_player, AccountStatus second_player) {
    return first_player > second_player;
  }

} // namespace hellmath
