import React, { Component } from 'react';
import PropTypes from 'prop-types';
import { CssBaseline, Container, AppBar, Toolbar, Typography, Paper, Grid, makeStyles, createStyles, withStyles, Box } from '@material-ui/core';

import Navbar from "./components/Navbar"
import Buts from "./components/initialbut"
import Traffic from "./components/traffic"

import socketIOClient from 'socket.io-client';

// import Notes from "./components/notes"

const useStyles = theme => ({
  root: {
    flexGrow: 1
  },
  tiles: {
    padding: theme.spacing(1),
    maxHeight: "1920px",
    height: "1920px",
    maxWidth: "1080px",
    width: "1080px",
    background: "radial-gradient(circle, rgba(94,90,90,1) 85%, rgba(0,0,0,0.865983893557423) 100%)",
  },
  car: {
    padding: theme.spacing(1),
    textAlign: "center",
    color: theme.palette.text.secondary,
    height: "500px"
  },
  traffic: {
    padding: theme.spacing(1),
    textAlign: "center",
    color: theme.palette.text.secondary,
    height: "240px",
  },
  circleStyle: {
    padding:10,
    margin:20,
    display:"inline-block",
    backgroundColor : "black",
    borderRadius: "50%",
    width:100,
    height:100,
}, 
  stress: {
    fontSize: 25,
  },
});

class App extends Component{
  constructor(props){
    super(props);
    this.state = {
      response: false,
      endpoint : "http://127.0.0.1:5000",
      ta : 0,
      tb : 0,
      sa : 0,
      sb : 0,
    };
  }

  getTraffic = states => {
    console.log(states);
    this.setState({sa : states.sa, sb : states.sb, ta : states.ta, tb : states.tb})
  }

  setTraffic = data => {
    console.log(data);
    const {classes} = this.props;
    if (data == 5){
    return(
      <div>
      <div className={classes.circleStyle}> </div>
      <div className={classes.circleStyle}> </div>
      <div className={classes.circleStyle} style={{backgroundColor: "green"}}> </div>
      </div>
    );} else if (data == 7){
      return(
      <div>
        <div className={classes.circleStyle}> </div>
        <div className={classes.circleStyle} style={{backgroundColor: "#feb236"}}> </div>
        <div className={classes.circleStyle}> </div>
      </div>
      )
    }
     else {
      return(
        <div>
        <div className={classes.circleStyle} style={{backgroundColor: "red"}}> </div>
        <div className={classes.circleStyle}> </div>
        <div className={classes.circleStyle}> </div>
        </div>
      );
    }
  }

  componentDidMount() {
    const {endpoint} = this.state;
    const socket = socketIOClient(endpoint);
    socket.on("traffic", this.getTraffic);
    // socket.on("traffic", data => this.setState({response: data.sa}));
  }

  // className={classes.tiles}
  render(){
    const {classes} = this.props;
    return (
      <React.Fragment>
        <CssBaseline />
        <Container fixed className={classes.tiles}>
        <Navbar />
        <br />
        <Grid container item xs={12} spacing={3}>
          <Grid item xs={6}>
          <Paper className={classes.car} elevation={10}> 
          </Paper>
        </Grid>
        <Grid item xs>
          <Paper className={classes.traffic} elevation={10}> 
          <Typography variant="h5"> Traffic 1 </Typography>
          {this.setTraffic(this.state.sa)}
            <Typography> Remaining time is {'\u00A0'}<b className={classes.stress}>{this.state.ta}</b>
            </Typography>
          </Paper>
          <br />
          <Paper className={classes.traffic} elevation={10}> 
          <Typography variant="h5"> Traffic 2 </Typography>
          {this.setTraffic(this.state.sb)}
            <Typography> Remaining time is {'\u00A0'}<b className={classes.stress}>{this.state.tb}</b>
            </Typography>
          </Paper>
        </Grid>
        </Grid>
        <br />
        <Buts />
      </Container>
      </React.Fragment>
    )
  }
}

App.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(useStyles)(App);
