import React, { PureComponent } from 'react';
import { BarChart, Bar, Rectangle, XAxis, YAxis, CartesianGrid, Tooltip, Legend, ResponsiveContainer } from 'recharts';

// dataset used to populate chart
const data = [
    {
        name: 'Page A',
        pv: 2400,
    },
    {
        name: 'Page B',
        pv: 1398,
    },
    {
        name: 'Page C',
        pv: 9800,
    },
    {
        name: 'Page D',
        pv: 3908,
    },
    {
        name: 'Page E',
        pv: 4800,
    },
    {
        name: 'Page F',
        pv: 3800,
    },
    {
        name: 'Page G',
        pv: 4300,
    },
];

// component Example that renders a bar chart using recharts
// PureComponent only re-renders when prop/state actually change
export default class Example extends PureComponent {
    static demoUrl = 'https://codesandbox.io/p/sandbox/simple-bar-chart-72d7y5';

    render() {
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
                        bottom: 5,
                    }}
                >
                    {/*adds a dashed grid background*/}
                    <CartesianGrid strokeDasharray="3 3" />
                    {/*XAxis uses name from each item*/}
                    {/*in dataset for the labels*/}
                    <XAxis dataKey="name" />
                    {/*scales based on value*/}
                    <YAxis />
                    {/*shows a tooltip on hover*/}
                    <Tooltip />
                    <Legend />
                    {/*activeBar defines custom styling on hover*/}
                    <Bar dataKey="pv" fill="#febd56" activeBar={<Rectangle fill="#82ca9d" stroke="blue" />} />
                    {/*<Bar dataKey="uv" fill="#82ca9d" activeBar={<Rectangle fill="gold" stroke="purple" />} />*/}
                </BarChart>
            </ResponsiveContainer>
        );
    }
}