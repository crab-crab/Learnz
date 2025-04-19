Coord-Hunt

# Basic Premise:

    Users are given a city/place and must guess the geographical coordinates (Latitude/Longitude),
    game will then return the distance guess was from actual location.

# Clone and Build:

    git clone git@github.com:crab-crab/Learnz.git
    cd projects/coord_hunt/
    make

# Current State:

    Method to calculate distance: Haversine Formula

# Limitations/Blindspots:

    Input file size is hard-coded, use countchar on input file to get newline count -> use as size

# Next Steps:

    Implement random choice of a location, display name to user, ask user for input guess.
    Compare user guess with location and return distance from target.

# Eventual features:

    Treasure hunt type trivia where user must make their way accross different locations.
    User will have limited distance/fuel budget.
    Possible use case for learning simple pathfinding?
        (would require linking locations to each other -> map data struture?)
        (naive or A* algorithm?)

# Further Info:

    https://aluminum-temple-24a.notion.site/Coord-Hunt-1ca1de8dc5fa80a0adf4d0de3a27bf5f

