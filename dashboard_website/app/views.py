from flask import Blueprint, render_template, url_for
import requests

views = Blueprint(__name__, 'views')

boardIP = 'Board IP here (ex rpico w)'

#functions here but move to other file later
@views.route('/led/on')
def turnLightOn():
    try:
        url = f'http://{boardIP}/led/on'
        response = requests.get(url).text
        return response
    except requests.exceptions.RequestException as e:
        print(e)
    
@views.route('/led/off')
def turnLightOff():
    try:
        url = f'http://{boardIP}/led/off'
        response = requests.get(url).text
        return response
    except requests.exceptions.RequestException as e:
        print(e)

# endpoints here
@views.route('/')
def index ():
    return render_template('index.html')