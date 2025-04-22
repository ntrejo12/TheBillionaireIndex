import React, { PureComponent } from 'react';
import { BarChart, Bar, Rectangle, XAxis, YAxis, CartesianGrid, Tooltip, Legend, ResponsiveContainer } from 'recharts';

// component Example that renders a bar chart using recharts
// PureComponent only re-renders when prop/state actually change
export default class Example extends PureComponent {
    static demoUrl = 'https://codesandbox.io/p/sandbox/simple-bar-chart-72d7y5';

    render() {
        const { data } = this.props;
        return (
            <ResponsiveContainer width="100%" height="100%">
                <BarChart
                    width={500}
                    height={300}
                    data={data}
                    margin={{
                        top: 5,
                        right: 30,
                        left: 20,
                        bottom: 100,
                    }}
                >
                    <CartesianGrid strokeDasharray="3 3"/> {/*adds a dashed grid background*/}
                    <XAxis dataKey="name"
                           interval={0}
                           angle={-45}
                           textAnchor="end"/> {/*XAxis uses name from each item*/} {/*in dataset for the labels*/}
                    <YAxis tickFormatter={(value) => `${(value / 1_000_000).toFixed(1)}M`}/> {/*scales based on value*/}
                    <Tooltip/> {/*shows a tooltip on hover*/}
                    {/*<Legend/>*/}
                    <Bar dataKey="annual_income"
                         fill="#febd56"
                         activeBar={<Rectangle fill="#82ca9d"
                                               stroke="blue"/>}/> {/*activeBar defines custom styling on hover*/}
                </BarChart>
            </ResponsiveContainer>
        );
    }
}