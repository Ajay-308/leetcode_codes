from geopy.geocoders import Nominatim
from geopy.distance import geodesic
import requests
import folium

ola_api_key = "pQvxeua7yMGMk9Q2yuDMlgWuLoXgXgBEnfVLGP7p"
starting = "Saket Apartments, 19, 1st Main Rd, 2nd Stage, Mshc Layout, Anandnagar, Hebbal, Bengaluru, Karnataka, 560024, India"
ending = "Sangam Vihar, Bus Stand, 5th Cross Rd, Near Munekollal, Thubarahalli, Marathahalli, Bengaluru, Karnataka, 560037, India"

geolocator = Nominatim(user_agent="geoapiExercises")

def get_location(address):
    location = geolocator.geocode(address)
    if location:
        return (location.latitude, location.longitude)
    else:
        raise ValueError(f"Could not find location for address: {address}")

start_pos = get_location(starting)
end_pos = get_location(ending)

def get_distance(starting, ending):
    distance = geodesic(starting, ending).kilometers
    return distance

print(f"Distance: {get_distance(start_pos, end_pos)} km")

def track_person(start, end):
    url = f"https://api.olamaps.io/routing/v1/directions?origin={start[0]},{start[1]}&destination={end[0]},{end[1]}&api_key={ola_api_key}"
    response = requests.post(url)
    if response.status_code == 200:
        return response.json()
    else:
        raise Exception(f"Error fetching directions: {response.status_code}")

# Get directions
direction = track_person(start_pos, end_pos)

# Print the full response to understand its structure
import json
print(json.dumps(direction, indent=2))

# Extract route coordinates based on actual response structure
route = []
for step in direction['routes'][0]['legs'][0]['steps']:
    if 'maneuver' in step and 'location' in step['maneuver']:
        location = step['maneuver']['location']
        if isinstance(location, list) and len(location) == 2:
            route.append((location[1], location[0]))  # Reverse order for folium

print(route)

# Create map
m = folium.Map(location=start_pos, zoom_start=15)

# Add start and end markers
folium.Marker(location=start_pos, tooltip="Start", popup="Starting point").add_to(m)
folium.Marker(location=end_pos, tooltip="End", popup="Ending point").add_to(m)

# Add route
if route:
    folium.PolyLine(locations=route, color='green', opacity=1).add_to(m)

# Save map
m.save("navigation_map.html")
print("Map saved as navigation_map.html")
